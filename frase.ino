#include <Wire.h> //Biblioteca para uso do protocolo I2C;
#include <Adafruit_GFX.h> //Biblioteca para manipulação gráfica no display;
#include <Adafruit_SH1106.h> //Biblioteca para operação do driver de controle do display;

#include <Fonts/FreeMono9pt7b.h> //Fonte para alteração do texto;
#include <Fonts/FreeSansBoldOblique9pt7b.h> //Fonte para alteração do texto;
#include <Fonts/FreeMonoOblique9pt7b.h> //Fonte para alteração do texto;

#define OLED_RESET -1 //Em displays que não possuem pino RESET, é dado o valor -1;

Adafruit_SH1106 display(OLED_RESET); //Declaração da tela com o nome "display";

void setup() {
  Serial.begin(9600);
  display.begin(SH1106_SWITCHCAPVCC, 0x3C); //Inicialização do display com a biblioteca e endereço de hardware do display;
}

void loop() {

  display.clearDisplay(); //Comando para limpar a tela;
  display.setFont(&FreeSansBoldOblique9pt7b); //Comando para definir a fonte que será utilizada;
  display.setTextColor(WHITE); //Comando para definir a cor do texto;
  display.setTextSize(1); //Comando para definir tamanho od
  
  display.setCursor(2, 15); //Definição de onde o texto será escrito. Lembre se que: linha, coluna; eixo x / eixo y
  display.print("A adversidade"); //Texto a ser escrito;
  display.setCursor(27, 30); //Definição de onde o texto será escrito. Lembre se que: linha, coluna; eixo x / eixo y
  display.print("revela o"); //Texto a ser escrito;
  display.setCursor(32, 45); //Definição de onde o texto será escrito. Lembre se que: linha, coluna; eixo x / eixo y
  display.print("talento"); //Texto a ser escrito;
  display.setCursor(55, 60); //Definição de onde o texto será escrito. Lembre se que: linha, coluna; eixo x / eixo y
  display.print("..."); //Texto a ser escrito;
  display.display(); 
  delay(3500);
  display.clearDisplay();
  display.setCursor(55, 15); //Definição de onde o texto será escrito. Lembre se que: linha, coluna; eixo x / eixo y
  display.print("A"); //Texto a ser escrito;
  display.setCursor(5, 30); //Definição de onde o texto será escrito. Lembre se que: linha, coluna; eixo x / eixo y
  display.print("Prosperidade"); //Texto a ser escrito;
  display.setCursor(55, 45); //Definição de onde o texto será escrito. Lembre se que: linha, coluna; eixo x / eixo y
  display.print("o"); //Texto a ser escrito;
  display.setCursor(25, 60); //Definição de onde o texto será escrito. Lembre se que: linha, coluna; eixo x / eixo y
  display.print("Esconde."); //Texto a ser escrito;
  display.display(); 
  delay(3500);
  display.clearDisplay();
 

  display.display(); //Mostrar informações na tela;
}
