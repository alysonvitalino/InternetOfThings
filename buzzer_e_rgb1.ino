// C++ code
//O BUZZER DEVERÁ TOCAR POR 5 SEGUNDOS, MEIO SEGUNDO
#define R 13
#define G 11
#define B 12
int buzzer = 8;
int i = 0;

void setup()
{
  pinMode(buzzer, OUTPUT);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
}

void loop()
{
  
  
  for(i=0;i<8;i++)
  {
    if(i==1)
    {
      tone(buzzer, 100, 1000);
      digitalWrite(R, HIGH);
      digitalWrite(G, LOW);
      digitalWrite(B, LOW);
      delay(1000);
 	  noTone(buzzer);
      delay(500);
    }
    else if (i==2)
    {
      tone(buzzer, 200, 1000);
      digitalWrite(R, LOW);
      digitalWrite(G, HIGH);
      digitalWrite(B, LOW);
      delay(1000);
 	  noTone(buzzer);
      delay(500);
    }
    else if (i==3)
    {
      tone(buzzer, 300, 1000);
      digitalWrite(R, LOW);
      digitalWrite(G, LOW);
      digitalWrite(B, HIGH);
      delay(1000);
 	  noTone(buzzer);
      delay(500);
    }
    else if (i==4)
    {
      tone(buzzer, 400, 1000);
      digitalWrite(R, HIGH);
      digitalWrite(G, LOW);
      digitalWrite(B, HIGH);
      delay(1000);
 	  noTone(buzzer);
      delay(500);
    }else if (i==5)
    {
      tone(buzzer, 500, 1000);
      digitalWrite(R, HIGH);
      digitalWrite(G, HIGH);
      digitalWrite(B, LOW);
  	  delay(1000);
 	  noTone(buzzer);
      delay(500);
    }
    else if (i==6)
    {
      tone(buzzer, 600, 1000);
      digitalWrite(R, LOW);
      digitalWrite(G, HIGH);
      digitalWrite(B, HIGH);
      delay(1000);
 	  noTone(buzzer);
      delay(500);
    }
    else if (i==7)
    {
      tone(buzzer, 700, 1000);
      digitalWrite(R, HIGH);
      digitalWrite(G, HIGH);
      digitalWrite(B, HIGH);
      delay(1000);
 	  noTone(buzzer);
      delay(500);
    }
  }
  
}