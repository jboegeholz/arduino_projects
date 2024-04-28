#include <Adafruit_NeoPixel.h>
#define PIN 4
#define NUMPIXELS 12 
Adafruit_NeoPixel modul_led_ring = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


void setup() {
  modul_led_ring.begin();

}

void loop() 
{
modul_led_ring.setPixelColor(0, modul_led_ring.Color(238,130,238));
modul_led_ring.setPixelColor(1, modul_led_ring.Color(238,130,238));

modul_led_ring.setPixelColor(2, modul_led_ring.Color(0,255,00));
modul_led_ring.setPixelColor(3, modul_led_ring.Color(0,255,0));

modul_led_ring.setPixelColor(4, modul_led_ring.Color(0,0,255));
modul_led_ring.setPixelColor(5, modul_led_ring.Color(0,0,255));

modul_led_ring.setPixelColor(6, modul_led_ring.Color(238,130,238));
modul_led_ring.setPixelColor(7, modul_led_ring.Color(238,130,238));

modul_led_ring.setPixelColor(8, modul_led_ring.Color(0,255,0));
modul_led_ring.setPixelColor(9, modul_led_ring.Color(0,255,0));

modul_led_ring.setPixelColor(10, modul_led_ring.Color(238,130,238));
modul_led_ring.setPixelColor(11, modul_led_ring.Color(238,130,238));

modul_led_ring.show();
}


