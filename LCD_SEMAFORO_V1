
// INCLUSÃO DE BIBLIOTECAS
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// DEFINIÇÕES
#define endereco  0x27 // Endereços comuns: 0x27, 0x3F
#define colunas   16
#define linhas    2

// INSTANCIANDO OBJETOS
LiquidCrystal_I2C lcd(endereco, colunas, linhas);

void setup() {
  pinMode(12, OUTPUT); // PEDESTRE VERDE
  pinMode(11, OUTPUT); // PEDESTRE VERMELHO 
  pinMode(10, OUTPUT); // VERDE CARRO
  pinMode(9, OUTPUT);  // AMARELO CARRO
  pinMode(8, OUTPUT);  // VERMELHO CARRO
  lcd.init(); // INICIA A COMUNICAÇÃO COM O DISPLAY
  lcd.backlight(); // LIGA A ILUMINAÇÃO DO DISPLAY
  lcd.clear(); // LIMPA O DISPLAY

}

void loop()
{
    digitalWrite(8, HIGH);
    digitalWrite(12, HIGH);
    lcd.setCursor(4,0);
    lcd.print("VERMELHO");
    lcd.setCursor(4,1);
    lcd.print("VERMELHO");
    delay(2000);
  	lcd.clear(); // LIMPA O DISPLAY
    digitalWrite(8, LOW);
    digitalWrite(12, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
  	lcd.setCursor(5,0);
    lcd.print("VERDE");
  	lcd.setCursor(5,1);
    lcd.print("VERDE");
    delay(3000);
  	lcd.clear();
    digitalWrite(10, LOW);
  	lcd.setCursor(4,0);
    lcd.print("AMARELO");
  	lcd.setCursor(4,1);
    lcd.print("AMARELO");
    digitalWrite(9, HIGH);
    delay(200);
    digitalWrite(9, LOW);
    delay(200);
    digitalWrite(9, HIGH);
    delay(200);
    digitalWrite(9, LOW);
    delay(200);
    digitalWrite(9, HIGH);
    delay(200);
  	lcd.clear();
    digitalWrite(11, LOW);
  	digitalWrite(9, LOW);
  
}
