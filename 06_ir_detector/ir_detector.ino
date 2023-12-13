void setup() {

  pinMode(11, INPUT);
  Serial.begin(9600);
}

void loop() {
  int rightIRSensorValue = digitalRead(11);
  Serial.println(rightIRSensorValue);
  delay(1000);
}
