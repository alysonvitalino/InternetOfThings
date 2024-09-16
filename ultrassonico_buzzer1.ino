/* 
	=======================================
	Pratica 25 - Sensor Ultrassom HC-SR04 e Buzzer
	
	Autor: Alberto Tolentino
	Criado em: 17/06/2020
	
	Demonstra o uso de sensor ultrassom
	simplificado HC-SR04 no Arduino. Ativa o
	Buzzer toda vez que sensor captar objeto
	a certa distância.
	
	Base do código utilizado
	https://www.tinkercad.com/things/5x4FbZMB0Wm
	=======================================    
*/
#define G 8
#define Y 9
#define R 10
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

}

void loop()
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
  
  if (cm <= 30 && cm > 20)
  {
  digitalWrite(R, LOW);
  digitalWrite(G, HIGH);
  digitalWrite(Y, LOW);
  } 
  else if (cm <= 20 && cm > 10)
  {
  digitalWrite(R, LOW);
  digitalWrite(G, LOW);
  digitalWrite(Y, HIGH);
  } 
  else if (cm <= 10)
  {
  digitalWrite(R, HIGH);
  digitalWrite(Y, LOW);
  digitalWrite(G, LOW);
  }
  else if (cm > 30)
  {
  digitalWrite(R, LOW);
  digitalWrite(Y, LOW);
  digitalWrite(G, LOW);
  }
  
}