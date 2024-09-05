// C++ code
//
#define R 3
#define G 6
#define B 5


void setup()
{
  Serial.begin(9600);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
}

void loop()
{
  analogWrite(R, 255);
  Serial.println("Cor: Vermelha.");
  delay(500);
  analogWrite(R, 0);
  
  analogWrite(G, 255);
  Serial.println("Cor: Verde.");
  delay(500);
  analogWrite(G, 0);
  
  analogWrite(B, 255);
  Serial.println("Cor: Azul.");
  delay(500);
  analogWrite(B, 0);
  
  analogWrite(R, 255);
  analogWrite(G, 255);
  Serial.println("Cor: Amarelo.");
  delay(500);
  analogWrite(R, 0);
  analogWrite(G, 0);
  
  analogWrite(R, 255);
  analogWrite(B, 255);
  Serial.println("Cor: Roxo.");
  delay(500);
  analogWrite(R, 0);
  analogWrite(B, 0);
  
  analogWrite(G, 255);
  analogWrite(B, 255);
  Serial.println("Cor: Ciano.");
  delay(500);
  analogWrite(G, 0);
  analogWrite(B, 0);
  
  analogWrite(R, 255);
  analogWrite(G, 255);
  analogWrite(B, 255);
  Serial.println("Cor: Branco.");
  delay(500);
  analogWrite(R, 0);
  analogWrite(G, 0);
  analogWrite(B, 0);
  
  
}