#include <LiquidCrystal.h>

#define RS 21
#define E  19
#define D4 14
#define D5 27
#define D6 26
#define D7 25

// Pinos do LCD
LiquidCrystal lcd(RS, E, D4, D5, D6, D7); 

void setup() {
  lcd.begin(20, 4);  // Inicializa o LCD e identifica que ele tem 20 colunas e 4 linhas
}

void loop() {
  lcd.clear(); // Apaga todos os caracteres do Display
  lcd.setCursor(0, 0); // Marca o cursor na posição coluna 0, linha 0
  lcd.print("MENSAGEM A"); // Escreve a mensagem na posição coluna 0, linha 0
  lcd.setCursor(0, 1);
  lcd.print("MENSAGEM B");
  lcd.setCursor(0, 2);
  lcd.print("MENSAGEM C");
  lcd.setCursor(0, 3);
  lcd.print("MENSAGEM D");
  delay(4000);
}

