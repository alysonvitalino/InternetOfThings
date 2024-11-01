#include <Wire.h> //Biblioteca para uso do protocolo I2C;
#include <Adafruit_GFX.h> //Biblioteca para manipulação gráfica no display;
#include <Adafruit_SH1106.h> //Biblioteca para operação do driver de controle do display;

#include <Fonts/FreeMono9pt7b.h> //Fonte para alteração do texto;
#include <Fonts/FreeSansBoldOblique9pt7b.h> //Fonte para alteração do texto;
#include <Fonts/FreeMonoOblique9pt7b.h> //Fonte para alteração do texto;

#define OLED_RESET -1 //Em displays que não possuem pino RESET, é dado o valor -1;

#include <SPI.h>
#include <MFRC522.h>
 
#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
 

Adafruit_SH1106 display(OLED_RESET); //Declaração da tela com o nome "display";

int LDR = 0;
int buzzer = 8; 
int tempPino = A0;
float tensao;
int display_mode = 0;
int tecla1 = 0;
int tecla2 = 0;
int tecla3 = 0;
int tecla4 = 0;
float temperaturaF; 

void temp_celsius() {
   int sensorTemp = analogRead(tempPino);
  tensao = sensorTemp * 5;
  tensao /= 1024;
  float temperaturaC = (tensao) * 100;

  int LDR = analogRead(A1);

  display.clearDisplay(); //Comando para limpar a tela;
  display.setFont(&FreeMonoOblique9pt7b); //Comando para definir a fonte que será utilizada;
  display.setTextColor(WHITE); //Comando para definir a cor do texto;
  display.setTextSize(1); //Comando para definir tamanho od

  display.setCursor(1, 15); //Definição de onde o texto será escrito. Lembre se que: linha, coluna;
  display.print("TEMPERATURA");  //Texto a ser escrito;
  display.setCursor(25, 30); 
  display.print(temperaturaC); //TEMPERATURA EM CELSIUS
  display.setCursor(85, 30);
  display.print("C");
  display.display();
}

String verif_card(){
          // Look for new cards
          String content = ""; // Declare content aqui

                  if ( ! mfrc522.PICC_IsNewCardPresent()) 
                  {
                    return "0";
                  }
                  // Select one of the cards
                  if ( ! mfrc522.PICC_ReadCardSerial()) 
                  {
                    return "0";
                  }

                  byte letter;
                  for (byte i = 0; i < mfrc522.uid.size; i++) 
                  {
                    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
                    Serial.print(mfrc522.uid.uidByte[i], HEX);
                    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
                    content.concat(String(mfrc522.uid.uidByte[i], HEX));
                  }

                  return content; 
}

int validate_card(String number_card) {
  if (number_card == " a3 7b fb 1a"){
      return 1;
    
  }  else {
    return 0;
  }  

}

void setDisplay(int opt, int display_mode) {
  if (opt == 1) {
    do{
      if (display_mode == 1){
        display.clearDisplay(); //Comando para limpar a tela;
        display.setFont(&FreeMonoOblique9pt7b); //Comando para definir a fonte que será utilizada;
        display.setTextColor(WHITE); //Comando para definir a cor do texto;
        display.setTextSize(1); //Comando para definir tamanho od

        display.setCursor(5, 15);
        display.print("MENU");
        display.setCursor(5, 45);
        display.print("[1] CONFIG");
        display.setCursor(5, 60);
        display.print("[2] BACK");
        display.display();

        tecla1 = digitalRead(2);
        tecla2 = digitalRead(3);

          if(tecla1){
            display_mode = 2;
          }
        }
    }while (display_mode ==1);
  }
}

void setup()
{
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522

  pinMode(A1, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(tempPino, INPUT);
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
}

void loop()
{
  menu_inicial:
    String content = ""; // Declare content aqui

  do{

  int sensorTemp = analogRead(tempPino);
  tensao = sensorTemp * 5;
  tensao /= 1024;
  float temperaturaC = (tensao) * 100;

  int LDR = analogRead(A1);

  display.clearDisplay(); //Comando para limpar a tela;
  display.setFont(&FreeMonoOblique9pt7b); //Comando para definir a fonte que será utilizada;
  display.setTextColor(WHITE); //Comando para definir a cor do texto;
  display.setTextSize(1); //Comando para definir tamanho od

  display.setCursor(1, 15); //Definição de onde o texto será escrito. Lembre se que: linha, coluna;
  display.print("TEMPERATURA");  //Texto a ser escrito;
  display.setCursor(25, 30); 
  display.print(temperaturaC); //TEMPERATURA EM CELSIUS
  display.setCursor(85, 30);
  display.print("C");
  display.display();

delay(500);
  	while (LDR<150){
      int sensorTemp = analogRead(tempPino);
      tensao = sensorTemp * 5;
      tensao /= 1024;
      temperaturaC = (tensao) * 100;

      LDR = analogRead(A1);

      display.clearDisplay(); //Comando para limpar a tela;
      display.setCursor(25, 15); //Definição de onde o texto será escrito. Lembre se que: linha, coluna;
      display.print(temperaturaC); //Texto a ser escrito;
      display.setCursor(85, 15);
      display.print("C");
      display.display();
      delay(500);
      display.clearDisplay(); //Comando para limpar a tela;
      display.setCursor(25, 15); //Definição de onde o texto será escrito. Lembre se que: linha, coluna;
      display.print(""); //Texto a ser escrito;]
      display.display();
      delay(100);
      tone(buzzer, 200, 1000);
      delay(100);
      noTone(buzzer);
      delay(500); 
    }

          // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }

  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }

  content.toUpperCase();

  acesso_autorizado:

  if (content.substring(1) == "A3 7B FB 1A"){
  display.clearDisplay();
  display.setCursor(1, 15);
  display.print("ACESSO");
  display.setCursor(1, 30);
  display.print("LIBERADO");
  display_mode = 1;
  }

  else {
  display.clearDisplay();
  display.setCursor(1, 15);
  display.print("ACESSO");
  display.setCursor(1, 30);
  display.print("NEGADO");
  }

  display.display();
  delay(2000);
    
  }while (content.substring(1) != "A3 7B FB 1A");

do{
  if (display_mode == 1){
  display.clearDisplay(); //Comando para limpar a tela;
  display.setFont(&FreeMonoOblique9pt7b); //Comando para definir a fonte que será utilizada;
  display.setTextColor(WHITE); //Comando para definir a cor do texto;
  display.setTextSize(1); //Comando para definir tamanho od

  display.setCursor(5, 15);
  display.print("MENU");
  display.setCursor(5, 45);
  display.print("[1] CONFIG");
  display.setCursor(5, 60);
  display.print("[2] BACK");
  display.display();

  tecla1 = digitalRead(2);
  tecla2 = digitalRead(3);

    if(tecla1){
      display_mode = 2;
    }

    if (tecla2) {
      display_mode = 7;
      goto menu_inicial;
    }
  }
  }while (display_mode ==1);

do{
    if (tecla1){
      display_mode = 2;
      display.clearDisplay();
      display.setCursor(5, 15);
      display.print("CONFIG");
      display.setCursor(5, 45);
      display.print("[3] - F");
      display.setCursor(5, 60);
      display.print("[4] - C");
      display.display();
      display.clearDisplay();
            tecla3 = digitalRead(4);
            tecla4 = digitalRead(5);

            if (tecla3){
              display_mode = 3;
            }

            if (tecla4){
              int temp;
              do {
                temp = 4;
                temp_celsius();

                String card1 = verif_card();

                if (card1 != "0" and card1 != ""){
                  temp = 2;
                  goto acesso_autorizado;
                  delay(500);
                }
              } while (temp == 4);
            }
    }

    }while (display_mode == 2);
do{
            
                  
                    display_mode = 3;
                    int LDR = analogRead(A1);

                      float temperaturaC;
                      int sensorTemp = analogRead(tempPino);
                      tensao = sensorTemp * 5;
                      tensao /= 1024;
                      temperaturaC = (tensao) * 100;

                      temperaturaF = (temperaturaC * 1.8) + 32;

                  display.clearDisplay(); //Comando para limpar a tela;
                  display.setFont(&FreeMonoOblique9pt7b); //Comando para definir a fonte que será utilizada;
                  display.setTextColor(WHITE); //Comando para definir a cor do texto;
                  display.setTextSize(1); //Comando para definir tamanho od

                  display.setCursor(1, 15); //Definição de onde o texto será escrito. Lembre se que: linha, coluna;
                  display.print("TEMPERATURA");  //Texto a ser escrito;
                  display.setCursor(25, 30); 
                  display.print(temperaturaF); //TEMPERATURA EM CELSIUS
                  display.setCursor(85, 30);
                  display.print("F");
                  display.display();
                  
                delay(500);
                    while (LDR<150){
                      LDR = analogRead(A1);
                      int sensorTemp = analogRead(tempPino);
                      tensao = sensorTemp * 5;
                      tensao /= 1024;
                      temperaturaC = (tensao) * 100;

                      temperaturaF = (temperaturaC * 1.8) + 32;

                      display.clearDisplay(); //Comando para limpar a tela;
                      display.setCursor(25, 15); //Definição de onde o texto será escrito. Lembre se que: linha, coluna;
                      display.print(temperaturaF); //Texto a ser escrito;
                      display.setCursor(85, 15);
                      display.print("F");
                      display.display();
                      delay(500);
                      display.clearDisplay(); //Comando para limpar a tela;
                      display.setCursor(25, 15); //Definição de onde o texto será escrito. Lembre se que: linha, coluna;
                      display.print(""); //Texto a ser escrito;]
                      display.display();
                      delay(100);
                      tone(buzzer, 200, 1000);
                      delay(100);
                      noTone(buzzer);
                      delay(500); 
                    }

                    String card = verif_card();

                    if (card != "0" and card != ""){
                      goto acesso_autorizado;
                      delay(500);
                    }

                  
                  
                  
            
} while (display_mode == 3);
do{
            if(tecla4){
              goto menu_inicial;
            }
      
    
} while (display_mode == 4);

    if (tecla2){
      goto menu_inicial;
    }
  
}

// Kami
