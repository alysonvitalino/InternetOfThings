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
  display.setCursor(10, 15); //Definição de onde o texto será escrito. Lembre se que: linha, coluna; eixo x / eixo y
  display.print("Matematica:"); //Texto a ser escrito;
  display.setCursor(5, 30); //Definição de onde o texto será escrito. Lembre se que: linha, coluna; eixo x / eixo y
  display.print("624-426 = 198"); //Texto a ser escrito;
  display.setCursor(2, 45); //Definição de onde o texto será escrito. Lembre se que: linha, coluna; eixo x / eixo y
  display.print("891+198=1089"); //Texto a ser escrito;


  display.drawRect(0, 0, 128, 64, WHITE); //Desenhar retângulo não-preenchido (pos x, pos y, largura, altura, cor);
 

  display.display(); //Mostrar informações na tela;
}
