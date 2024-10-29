int touch = 0;

void setup() {

  pinMode(8, INPUT);
  pinMode(9, OUTPUT);

}

void loop() {
 
 touch = digitalRead(8);

 if(touch==1)
 {
  digitalWrite(9, HIGH);
 }
 else
 {
  digitalWrite(9, LOW);
 }

}

