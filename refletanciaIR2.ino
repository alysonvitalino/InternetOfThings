#include <Wire.h> //Biblioteca para uso do protocolo I2C;
#include <Adafruit_GFX.h> //Biblioteca para manipulação gráfica no display;
#include <Adafruit_SH1106.h> //Biblioteca para operação do driver de controle do display;

#include <Fonts/FreeMono9pt7b.h> //Fonte para alteração do texto;
#include <Fonts/FreeSansBoldOblique9pt7b.h> //Fonte para alteração do texto;
#include <Fonts/FreeMonoOblique9pt7b.h> //Fonte para alteração do texto;

#define OLED_RESET -1 //Em displays que não possuem pino RESET, é dado o valor -1;
#define pinSensor1 7
int leitura = 0;
Adafruit_SH1106 display(OLED_RESET); //Declaração da tela com o nome "display";

void setup() {
  Serial.begin(9600);
  pinMode(pinSensor1, INPUT);
  pinMode(A0, INPUT);
  display.begin(SH1106_SWITCHCAPVCC, 0x3C); //Inicialização do display com a biblioteca e endereço de hardware do display;
}

void loop() {

  leitura = analogRead(A0);
  bool estadoSensor1 = digitalRead(pinSensor1);

  display.clearDisplay(); //Comando para limpar a tela;
  display.setFont(&FreeSansBoldOblique9pt7b); //Comando para definir a fonte que será utilizada;
  display.setTextColor(WHITE); //Comando para definir a cor do texto;
  display.setTextSize(1); //Comando para definir tamanho od

    if (estadoSensor1)
    {
      Serial.println("PRETO (ou nada)");
      display.setCursor(5, 30); //Definição de onde o texto será escrito. Lembre se que: linha, coluna; eixo x / eixo y
      display.print("OBSTACULO"); //Texto a ser escrito;
      display.setCursor(20, 45); //Definição de onde o texto será escrito. Lembre se que: linha, coluna; eixo x / eixo y
      display.print("NA VISAO");
      display.setCursor(50, 60); //Definição de onde o texto será escrito. Lembre se que: linha, coluna; eixo x / eixo y
      display.print(leitura);
      display.display();
      display.clearDisplay();
    } else
      { 
        Serial.println("BRANCO (diferente de preto)");
        display.setCursor(50, 60); //Definição de onde o texto será escrito. Lembre se que: linha, coluna; eixo x / eixo y
        display.print(leitura);
        display.setCursor(30, 30); //Definição de onde o texto será escrito. Lembre se que: linha, coluna; eixo x / eixo y
        display.print("PROCU");
        display.setCursor(30, 45); //Definição de onde o texto será escrito. Lembre se que: linha, coluna; eixo x / eixo y
        display.print("RANDO");
        display.display();
        display.clearDisplay();
      }
}