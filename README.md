# SafeVax

## Problema Abordado
O armazenamento adequado de vacinas em ambientes hospitalares é essencial para manter sua eficácia. A violação de condições ideais, como abertura excessiva das portas de refrigeradores ou variações de temperatura, pode comprometer a qualidade das vacinas, colocando em risco a saúde pública. No entanto, o monitoramento desses fatores muitas vezes depende de processos manuais, sujeitos a falhas humanas.

## Solução Proposta
SafeVax é um sistema automatizado projetado para monitorar a abertura e fechamento das portas de refrigeradores de vacinas, além de acompanhar a temperatura interna em tempo real. Futuramente, o sistema também incluirá identificação de quem acessa o refrigerador, utilizando tecnologia de leitura de cartões RFID. Dessa forma, o SafeVax garante maior controle, segurança e eficiência no armazenamento de vacinas.

## Ferramentas Utilizadas
- **ESP32**: Microcontrolador para integração e controle dos sensores.
- **Sensor DHT11**: Para monitorar a temperatura interna em tempo real.
- **Sensor de RFID**: Para identificação de quem acessa o refrigerador.
- **Sensor para detecção de abertura e fechamento de portas**: Para monitorar acessos ao refrigerador.
- **Software de monitoramento**: Para exibição e registro dos dados capturados.
- **Envio de alertas via WhatsApp**: Notificações automáticas para gerentes do hospital em casos de irregularidades.

## Implementações Futuras
- **Leitura de RFID**: Registro de quem acessou o refrigerador, garantindo rastreabilidade e responsabilidade. 
- **Integração com sistemas hospitalares**: Sincronização de dados com plataformas de gestão de saúde.
- **Relatórios automáticos**: Análise de dados históricos para otimizar práticas de armazenamento e logística.

SafeVax é um passo em direção a um armazenamento de vacinas mais seguro e confiável, reduzindo riscos e aumentando a eficiência no gerenciamento hospitalar.
