/*
     CÓDIGO:  Q0624
     AUTOR:   BrincandoComIdeias
     LINK:    https://www.youtube.com/brincandocomideias ; https://cursodearduino.net/ ; https://cursoderobotica.net
     COMPRE:  https://www.arducore.com.br/
     SKETCH:  Exemplo LiquidCrystal_I2C
     DATA:    11/02/2020
*/

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

void loop() {

  // Faz a leitura da tensao no Sensor de Temperatura
	int SensorTempTensao=analogRead(A0);
  	// Converte a tensao lida
	float Tensao=SensorTempTensao*5;
	Tensao/=1024;
  	// Converte a tensao lida em Graus Celsius
	float TemperaturaC=Tensao*100;
  
  lcd.setCursor(6,0);          
  lcd.print(TemperaturaC); 
  lcd.setCursor(2,1);
  lcd.print("FUNCIONOU!!!");
  delay(1000); // DELAY DE 2 SEGUNDOS
  
  lcd.clear(); // LIMPA O DISPLAY
  //lcd.noBacklight(); // DESLIGA A ILUMINAÇÃO DO DISPLAY

}
