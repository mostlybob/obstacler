//borrowed code from https://circuits4you.com/2016/05/13/ultrasonic-sensor-sr04-arduino/

int trigPin = 11;    //Trig - green Jumper
int echoPin = 12;    //Echo - yellow Jumper
long duration, cm, inches;

void setup() {

  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // convert the time into a distance
  cm = (duration/2) / 29.1;
  inches = (duration/2) / 74; 
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(250);

}
