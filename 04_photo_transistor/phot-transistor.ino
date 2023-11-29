const int photodiodePin = A0; // Wählen Sie den Pin für die Photodiode

void setup() {
  Serial.begin(9600); // Starten des seriellen Kommunikationsports
}

void loop() {
  int sensorValue = analogRead(photodiodePin); // Lesen des Photodiode-Werts
  Serial.println(sensorValue); // Ausgabe des Wertes im seriellen Monitor
  delay(1000); // Kurze Pause für die Lesbarkeit der Ausgabe
}