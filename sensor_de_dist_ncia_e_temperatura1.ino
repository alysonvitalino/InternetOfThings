int buzzer = 9;
int botao = 0;
const int pinoBuzzer = 9; //PINO DIGITAL EM QUE O BUZZER ESTÁ CONECTADO

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
  pinMode(2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(13, INPUT);

}

void loop()
{
  
  botao = digitalRead(13);
  
  if(botao==1)
  {
    digitalWrite(2, LOW);
    delay(100000);
  }
  if(botao==0)
  {
    cm = 0.01723 * readUltrasonicDistance(5, 7);
  	if(cm < 20)
    {
  
    // measure the ping time in cm
  	Serial.print(cm);
  	Serial.println(" cm");
  	delay(100); // Wait for 100 millisecond(s)
      
      
  	//ACENDE O LED
  	digitalWrite(2, HIGH);
  	
  	//LIGA O BUZZER
  	tone(buzzer, 250, 1000);
  	delay(500);
  	noTone(buzzer);
  
  	
  	
  	// Faz a leitura da tensao no Sensor de Temperatura
	int SensorTempTensao=analogRead(A0);

  	// Converte a tensao lida
	float Tensao=SensorTempTensao*5;
	Tensao/=1024;

  	// Converte a tensao lida em Graus Celsius
	float TemperaturaC=(Tensao-0.5)*100;
  	
  	//PRINTA A TEMPERATURA AMBIENTE
    Serial.print(TemperaturaC);
    Serial.println(" Graus Celsius");
      
    }
  	else
    {
    digitalWrite(2, LOW);
    }
  }
  
 
  	
}

