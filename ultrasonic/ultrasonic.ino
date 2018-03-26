//borrowed code from https://circuits4you.com/2016/05/13/ultrasonic-sensor-sr04-arduino/

int triggerPin = 11;
int echoPin = 12;
long duration, cm, inches;

void setup() {
  Serial.begin (9600);

  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {
  duration = checkPingDuration();

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

long checkPingDuration(){
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(5);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);

  return pulseIn(echoPin, HIGH);
}
