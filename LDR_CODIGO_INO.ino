// C++ code
//
int LDR = 0;
int LED = 9;
void setup()
{
  
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(A0, INPUT);
}

void loop()
{
  int LDR = analogRead(A0);
  
  if (LDR<=650) 
  {
    digitalWrite(LED, HIGH);
    Serial.println("LED LIGADO!");
    Serial.println(LDR);
  } else {
    digitalWrite(LED, LOW);
    Serial.println("LED DESLIGADO!");
    Serial.println(LDR);
  }
  delay (1000);
  
}