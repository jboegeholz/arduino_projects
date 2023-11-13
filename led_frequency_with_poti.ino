void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);
  Serial.println("Wert vom Poti: " + String(sensorValue));
  if (sensorValue <= 10) {
    digitalWrite(LED_BUILTIN, LOW);
  } else {
    int delayTime = -0.5 * sensorValue + 522;
    Serial.println("Errechnete DelayTime: " + String(delayTime));
    digitalWrite(LED_BUILTIN, HIGH);
    delay(delayTime);
    digitalWrite(LED_BUILTIN, LOW);
    delay(delayTime);
  }


}
