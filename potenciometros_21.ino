// C++ code
//
int poten1 = 0;
int poten2 = 0;
void setup()
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
}

void loop()
{
  poten1 = analogRead(A0);
  poten2 = analogRead(A1);
  if(poten1 > 511 && poten2 > 511)
  {
    Serial.println("Para cima e para direita");
    delay(1000);
  }
  else if(poten1 > 511 && poten2 < 511)
  {
    Serial.println("Para cima e para esquerda");
    delay(1000);
  }
  else if(poten1 < 511 && poten2 < 511)
  {
    Serial.println("Para baixo e para esquerda");
    delay(1000);
  }
  else if(poten1 < 511 && poten2 > 511)
  {
    Serial.println("Para baixo e para direita");
    delay(1000);
  }
}