void setup() {

  pinMode(11, INPUT);
  pinMode(12, INPUT);
  Serial.begin(9600);
}

void loop() {
  int rightIRSensorValue = digitalRead(11);
  int leftIRSensorValue = digitalRead(12);
  Serial.println(rightIRSensorValue);
  Serial.println(leftIRSensorValue);
  delay(1000);
}
