#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include <DHT.h>

// Configurações do sensor DHT11
#define DHT_PIN 4          // GPIO onde o sensor DHT11 está conectado
#define DHT_TYPE DHT11     // Define o tipo do sensor
DHT dht(DHT_PIN, DHT_TYPE);

// Configurações do sensor ultrassônico HC-SR04
#define TRIG_PIN 5  // GPIO do pino TRIG
#define ECHO_PIN 18 // GPIO do pino ECHO

// Configuração do LED indicador
#define LED_PIN 2 // GPIO do pino do LED

// Configurações da rede Wi-Fi
const char* ssid = "Starlink_CIT";
const char* password = "Ufrr@2024Cit";

// Configurações do HiveMQ (broker MQTT)
const char* mqtt_server = "cd8839ea5ec5423da3aaa6691e5183a5.s1.eu.hivemq.cloud";
const int mqtt_port = 8883;
const char* mqtt_topic_temp = "esp32/dht11/temperatura";
const char* mqtt_topic_porta = "esp32/refrigerador/status";
const char* mqtt_username = "hivemq.webclient.1734636778463";
const char* mqtt_password = "EU<pO3F7x?S%wLk4#5ib";

// Inicialização do cliente Wi-Fi e MQTT com TLS
WiFiClientSecure espClient;
PubSubClient client(espClient);

// Variáveis auxiliares
unsigned long lastMsg = 0;
const int intervalo = 5000;
const float distancia_limite = 10.0; // Distância limite em cm para a porta
unsigned long portaAbertaDesde = 0;  // Momento em que a porta foi detectada aberta
bool ledEstado = false;              // Estado atual do LED

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT); // Configura o LED como saída

  // Conecta à rede Wi-Fi
  setup_wifi();

  // Configura o cliente MQTT
  espClient.setInsecure(); // Permite conexões TLS sem validar certificados
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback); // Adiciona callback para mensagens recebidas
  
  dht.begin();
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Envia dados a cada intervalo definido
  unsigned long now = millis();
  if (now - lastMsg > intervalo) {
    lastMsg = now;

    // Envia dados do DHT11
    enviarTemperatura();

    // Envia dados do HC-SR04
    verificarPorta();
  }

  // Atualiza o estado do LED
  gerenciarLED(now);
}

// Função para conectar ao Wi-Fi
void setup_wifi() {
  delay(10);
  Serial.println("Conectando à rede Wi-Fi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWi-Fi conectado!");
  Serial.println("Endereço IP: ");
  Serial.println(WiFi.localIP());
}

// Função para reconectar ao MQTT
void reconnect() {
  while (!client.connected()) {
    Serial.println("Tentando reconectar ao HiveMQ...");
    if (client.connect("ESP32_Client", mqtt_username, mqtt_password)) {
      Serial.println("Conectado ao HiveMQ!");
      client.subscribe(mqtt_topic_temp); // Exemplo de assinatura de tópico
    } else {
      Serial.print("Falha, rc=");
      Serial.print(client.state());
      Serial.println(". Tentando novamente em 5 segundos...");
      delay(5000);
    }
  }
}

// Callback para processar mensagens recebidas
void callback(char* topic, byte* message, unsigned int length) {
  Serial.print("Mensagem recebida em [");
  Serial.print(topic);
  Serial.print("]: ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
  }
  Serial.println();
}

// Função para enviar dados de temperatura e umidade
void enviarTemperatura() {
  float temperatura = dht.readTemperature();
  float umidade = dht.readHumidity();

  if (!isnan(temperatura) && !isnan(umidade)) {
    String mensagem = "Temperatura: " + String(temperatura) + " °C, Umidade: " + String(umidade) + " %";
    if (client.publish(mqtt_topic_temp, mensagem.c_str())) {
      Serial.println("Temperatura enviada!");
    } else {
      Serial.println("Falha ao enviar temperatura.");
    }
  } else {
    Serial.println("Erro ao ler o sensor DHT11.");
  }
}

// Verifica o estado da porta e atualiza o tempo de abertura
void verificarPorta() {
  float distancia = medirDistancia();
  if (distancia > distancia_limite) {
    if (portaAbertaDesde == 0) {
      portaAbertaDesde = millis(); // Marca o momento em que a porta foi detectada aberta
    }
  } else {
    portaAbertaDesde = 0; // Reseta o tempo quando a porta é fechada
    digitalWrite(LED_PIN, LOW); // Garante que o LED está apagado
  }
}

// Função para gerenciar o estado do LED
void gerenciarLED(unsigned long now) {
  if (portaAbertaDesde > 0 && now - portaAbertaDesde > 10000) {
    // Pisca o LED se a porta estiver aberta por mais de 10 segundos
    if (now % 1000 < 500) {
      digitalWrite(LED_PIN, HIGH);
    } else {
      digitalWrite(LED_PIN, LOW);
    }
  }
}

// Função para medir distância com HC-SR04
float medirDistancia() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duracao = pulseIn(ECHO_PIN, HIGH);
  return (duracao * 0.034) / 2.0;
}
