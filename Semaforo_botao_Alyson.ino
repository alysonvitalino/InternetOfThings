// C++ code
//
int botao = 0;
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  botao = digitalRead(10);
  if (botao == HIGH)
  {
    digitalWrite(1, HIGH);
    delay(1000);
  } 
  else
  {
    digitalWrite(1, LOW);
    delay(1000);
  }
}