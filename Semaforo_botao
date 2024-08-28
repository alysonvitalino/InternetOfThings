// C++ code
//
int botaosemaforo = 0;
void setup()
{
  pinMode(13, INPUT); // BOTÃO
  pinMode(7, OUTPUT); // VERDE
  pinMode(4, OUTPUT); // AMARELO
  pinMode(1, OUTPUT); // VERMELHO
  pinMode(11, OUTPUT); // PEDESTRE VERDE
  pinMode(9, OUTPUT); // PEDESTRE VERMELHO
}

void loop()
{
  
  botaosemaforo = digitalRead(13);
  if (botaosemaforo == HIGH)
  {
    digitalWrite(7, HIGH);
    digitalWrite(9, HIGH);
    delay(3000);
    digitalWrite(7, LOW);
    digitalWrite(4, HIGH);
    delay(1000);
    digitalWrite(4, LOW);
    digitalWrite(9, LOW);
    digitalWrite(1, HIGH);
    delay(500);
    digitalWrite(11, HIGH);
    delay(1500);
    digitalWrite(11,LOW);
    digitalWrite(1,LOW);
  }
}
