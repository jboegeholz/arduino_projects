const int pwmPin = 9; // Use a PWM-capable pin

void setup() {
  // Initialize the PWM pin as an output
  pinMode(pwmPin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);
  Serial.println("Wert vom Poti: " + String(sensorValue));
  int brightness = sensorValue/4;

  analogWrite(9, brightness);


}