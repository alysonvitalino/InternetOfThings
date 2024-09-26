
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
 
  lcd.init(); // INICIA A COMUNICAÇÃO COM O DISPLAY
  lcd.backlight(); // LIGA A ILUMINAÇÃO DO DISPLAY
  lcd.clear(); // LIMPA O DISPLAY

}

void loop()
{
   
    lcd.setCursor(0,0);
    lcd.print(" . . . . . . . .");
    lcd.setCursor(0,1);
    lcd.print(". . . . . . . . .");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(". . . . . . . . .");
    lcd.setCursor(0,1);
    lcd.print(" . . . . . . . .");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(".................");
    lcd.setCursor(0,1);
    lcd.print(".................");
    delay(1000);
    lcd.clear();
    delay(500);
    lcd.setCursor(0,0);
    lcd.print(".................");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print(".................");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("........            ");
    lcd.setCursor(0,1);
    lcd.print("........            ");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("        ........");
    lcd.setCursor(0,1);
    lcd.print("        ........");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("....        ....");
    lcd.setCursor(0,1);
    lcd.print("....        ....");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("    ........    ");
    lcd.setCursor(0,1);
    lcd.print("    ........    ");
    delay(1000);
    lcd.clear();
}
