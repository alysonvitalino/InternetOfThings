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
  Serial.print("Posicao X: ");
  Serial.print(poten1);
  Serial.print("  Posicao Y: ");
  Serial.println(poten2);
  delay(4000);
}