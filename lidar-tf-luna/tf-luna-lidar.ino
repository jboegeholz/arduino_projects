#include <SoftwareSerial.h>

SoftwareSerial LidarSerial(2, 3); // RX, TX

void setup() {
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Native USB only
  }
  Serial.println("Let's go");

  LidarSerial.begin(115200);

}

void loop() {

  if (LidarSerial.available()) {

    if (LidarSerial.read() == 0x59) { // Check for the first header byte
      if (LidarSerial.read() == 0x59) { // Check for the second header byte
        int distance = LidarSerial.read() + LidarSerial.read() * 256;
        int strength = LidarSerial.read() + LidarSerial.read() * 256;
        for (int i = 0; i < 3; i++) {
          LidarSerial.read();
        }

        // Drucken Sie die Entfernung auf der seriellen Konsole.
        Serial.print("Distance: ");
        Serial.print(distance);
        Serial.print("cm ");
        Serial.print("Strength: ");
        Serial.print(strength);
        Serial.println("");

      }
    }
  }
}