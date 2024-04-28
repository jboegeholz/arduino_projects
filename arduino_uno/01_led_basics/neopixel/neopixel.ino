#include <Adafruit_NeoPixel.h>
#define PIN 4
#define NUMPIXELS 12 
Adafruit_NeoPixel modul_led_ring = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  modul_led_ring.begin();
}

void loop() {
  for(int i = 0; i < NUMPIXELS; i++) {
    modul_led_ring.clear(); // Schaltet alle LEDs aus
    modul_led_ring.setPixelColor(i, modul_led_ring.Color(255, 150, 0)); // Orangefarbene LEDs
    modul_led_ring.show();
    delay(500); // Warte 500ms zwischen den Änderungen
  }
}


