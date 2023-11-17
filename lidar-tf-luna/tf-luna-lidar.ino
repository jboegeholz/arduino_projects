#include <SoftwareSerial.h>

SoftwareSerial TFSerial(2, 3); // RX, TX

void setup() {
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Native USB only
  }
  Serial.println("Let's go");


  TFSerial.begin(115200);

}

void loop() {

  if (TFSerial.available()) {

    if (TFSerial.read() == 0x59) { // Check for the first header byte
      if (TFSerial.read() == 0x59) { // Check for the second header byte
        int distance = TFSerial.read() + TFSerial.read() * 256;
        int strength = TFSerial.read() + TFSerial.read() * 256;
        for (int i = 0; i < 3; i++) {
          TFSerial.read();
        }

        // Drucken Sie die Entfernung auf der seriellen Konsole.
        Serial.print("Distance: ");
        Serial.print(distance);
        Serial.println("cm");
        Serial.print("Strength: ");
        Serial.print(strength);
        Serial.println("cm");

      }
    }
  }
}