void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);
  Serial.println("Wert vom Poti: " + String(sensorValue));
  delay(1000);

}
