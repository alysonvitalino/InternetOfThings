#define P1 8
#define P2 9
#define P3 10
#define P4 11

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>

// Definições do display OLED
#define OLED_RESET -1
Adafruit_SH1106 display(OLED_RESET);
#define SENSOR_PIN 2 
int p1, p2, p3, p4;
int numeros[6];
const int tamanho = sizeof(numeros) / sizeof(numeros[0]);

String passwordGenerate() {
  String password = "";

  for (int i = 0; i < 6; i++) { 
    numeros[i] = generateNumbers();
    delay(100); 
  }

  String resultado = joinArray(numeros, tamanho, "");
  return resultado;
}

String joinArray(const int array[], int tamanho, const char* delimitador) {
  String resultado = ""; 
  for (int i = 0; i < tamanho; i++) {
    resultado += String(array[i]); 
    if (i < tamanho - 1) {        
      resultado += delimitador;
    }
  }
  return resultado;
}

int generateNumbers() {
  while (true) { 
    p1 = digitalRead(P1);
    p2 = digitalRead(P2);
    p3 = digitalRead(P3);
    p4 = digitalRead(P4);

    if (p1 == 1) return 1;
    if (p2 == 1) return 2;
    if (p3 == 1) return 3;
    if (p4 == 1) return 4;

    delay(50);
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(P1, INPUT);
  pinMode(P2, INPUT);
  pinMode(P3, INPUT);
  pinMode(P4, INPUT);

  display.begin(SH1106_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
}

void loop() {
  String password = passwordGenerate();
  Serial.println(password);

  display.clearDisplay();
  display.setCursor(0, 30);

  display.print("Senha: " + password);
  display.setCursor(0, 50);

  if (password == "123412") {
    Serial.println("Senha correta");
    display.print("Senha correta");
  } else {
    Serial.println("Senha incorreta");
    display.print("Senha incorreta");
  }

  display.display();
  delay(1000);
}
