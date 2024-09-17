
#define G 8
#define Y 9
#define R 10
int buzzer = 2;
int botao = 0;
const int pinoBuzzer = 2; //PINO DIGITAL EM QUE O BUZZER ESTÁ CONECTADO

int inches = 0;

int cm = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  pinMode(R, OUTPUT);
  pinMode(Y, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(12, INPUT);
  pinMode(buzzer, OUTPUT);
  

}

void loop()
{
  
  
  botao = digitalRead(12);
  
  if(botao == HIGH)
  {
  // measure the ping time in cm
  cm = 0.01723 * readUltrasonicDistance(5, 7);
  // convert to inches by dividing by 2.54
  inches = (cm / 2.54);
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.println("cm");
  delay(100); // Wait for 100 millisecond(s)
  
  if (cm > 20)
  {
  digitalWrite(R, LOW);
  digitalWrite(G, HIGH);
  digitalWrite(Y, LOW);
  tone(buzzer, 500, 1000);
  delay(3000);
  noTone(buzzer);
  } 
  else if (cm <= 20 && cm > 10)
  {
  digitalWrite(R, LOW);
  digitalWrite(G, LOW);
  digitalWrite(Y, HIGH);
  tone(buzzer, 500, 1000);
  delay(1500);
  noTone(buzzer);
  } 
  else if (cm <= 10)
  {
  digitalWrite(R, HIGH);
  digitalWrite(Y, LOW);
  digitalWrite(G, LOW);
  tone(buzzer, 500, 1000);
  delay(500);
  noTone(buzzer);
  }
  }
  else 
  {
  digitalWrite(R, LOW);
  digitalWrite(Y, LOW);
  digitalWrite(G, LOW);
  }
  
  
}