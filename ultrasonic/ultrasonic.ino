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

  cm = getCentimetresFromDuration(duration);
  inches = getInchesFromDuration(duration); 
  
  outputDistances(cm, inches);

  delay(250);
}

void outputDistances(float cm, float inches){
  // it'd be nice to figure out the string formatting functions available
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
}

float getInchesFromDuration(long duration){
  return (duration/2) / 74;
}

float getCentimetresFromDuration(long duration){
  return (duration/2) / 29.1;
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
