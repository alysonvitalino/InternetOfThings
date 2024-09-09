#define R 12
#define G 9
#define B 10

void setup()
{
  
  Serial.begin(9600);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(A0, INPUT);
}

void loop()
{
  int LDR = analogRead(A0);
  
  if (LDR<=150) 
  {
    digitalWrite(B, LOW);
    digitalWrite(G, LOW);
    digitalWrite(R, HIGH);
    Serial.println("VERMELHO LIGADO!");
    Serial.println(LDR);
    delay (1000);
   
    
  }  
  else if (LDR<=300)
  {
    digitalWrite(R, LOW);
    digitalWrite(B, LOW);
    Serial.println(LDR);
    Serial.println("VERDE LIGADO!");
    digitalWrite(G, HIGH);
    delay (1000);
    
    
  }
  else if(LDR<=450)
  {
    digitalWrite(G, LOW);
    digitalWrite(R, LOW);
    Serial.println(LDR);
    Serial.println("AZUL LIGADO!");
    digitalWrite(B, HIGH);
    delay (1000);
    
  }
  else if (LDR<=600)
  {
    digitalWrite(B, LOW);
    Serial.println(LDR);
    Serial.println("AMARELO LIGADO!");
    digitalWrite(R, HIGH);
    digitalWrite(G, HIGH);
    delay (1000);
  }
  else if (LDR<=750)
  {
    digitalWrite(R, LOW);
    digitalWrite(G, LOW);
    Serial.println(LDR);
    Serial.println("ROXO LIGADO!");
    digitalWrite(R, HIGH);
    digitalWrite(B, HIGH);
    delay (1000);
  }
  else if (LDR<=900)
  {
    digitalWrite(R, LOW);
    digitalWrite(B, LOW);
    Serial.println(LDR);
    Serial.println("CIANO LIGADO!");
    digitalWrite(G, HIGH);
    digitalWrite(B, HIGH);
    delay (1000);
  }
  else if (LDR>900)
  {
    digitalWrite(B, LOW);
    digitalWrite(G, LOW);
    Serial.println(LDR);
    Serial.println("BRANCO LIGADO!");
    digitalWrite(R, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(B, HIGH);
    delay (1000);
  }
  delay (1000);
  
}