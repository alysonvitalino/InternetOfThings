
// INCLUSÃO DE BIBLIOTECAS
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// DEFINIÇÕES
#define endereco  0x3F // Endereços comuns: 0x27, 0x3F
#define colunas   16
#define linhas    2

// INSTANCIANDO OBJETOS
LiquidCrystal_I2C lcd(endereco, colunas, linhas);

void setup() {
  pinMode(8, OUTPUT); // PEDESTRE VERDE
  pinMode(9, OUTPUT); // PEDESTRE VERMELHO 
  pinMode(10, OUTPUT); // VERDE CARRO
  pinMode(11, OUTPUT);  // AMARELO CARRO
  pinMode(12, OUTPUT);  // VERMELHO CARRO
  lcd.init(); // INICIA A COMUNICAÇÃO COM O DISPLAY
  lcd.backlight(); // LIGA A ILUMINAÇÃO DO DISPLAY
  lcd.clear(); // LIMPA O DISPLAY

}

void loop()
{
    digitalWrite(8, HIGH);
    digitalWrite(12, HIGH);
    lcd.setCursor(0,0);
    lcd.print("CARRO VERMELHO");
    lcd.setCursor(0,1);
    lcd.print("PEDESTRE VERDE");
    delay(6000);
  	lcd.clear(); // LIMPA O DISPLAY
    digitalWrite(8, LOW);
    digitalWrite(12, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
  	lcd.setCursor(0,0);
    lcd.print("CARRO VERDE");
  	lcd.setCursor(0,1);
    lcd.print("PEDESTRE VERMELHO");
    delay(9000);
  	lcd.clear();
    digitalWrite(10, LOW);
  	lcd.setCursor(0,0);
    lcd.print("CARRO AMARELO");
  	lcd.setCursor(0,1);
    lcd.print("PEDESTRE VERMELHO");
    digitalWrite(11, HIGH);
    delay(2000);
    digitalWrite(11, LOW);
    delay(2000);
    digitalWrite(11, HIGH);
    delay(2000);
    digitalWrite(11, LOW);
    delay(2000);
    digitalWrite(11, HIGH);
    delay(2000);
  	lcd.clear();
    digitalWrite(11, LOW);
  	digitalWrite(9, LOW);
  
}
