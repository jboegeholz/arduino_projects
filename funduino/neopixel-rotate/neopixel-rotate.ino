#include <Adafruit_NeoPixel.h> // Einbindung der Adafruit_Neopixel.h Bibliothek
#define PIN 4 // An welchem digitalen Pin ist der WS2812B Ring mit dem Mikrocontroller verbunden
#define NUMPIXELS 12 // Über wie viele Pixel verfügt der WS2812B Ring?

Adafruit_NeoPixel modul_led_ring = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800); // Konfiguration des Objektes modul_led_ring

//int color[3]      = {80,10,88}; // violet
int color[3]      = {255,165,0};


void setup()
{
  modul_led_ring.begin(); // Initialisierung des WS2812B LED Rings
  modul_led_ring.show();
}

void loop()
{

  for(int i = 0; i < 12; ++i){
    modul_led_ring.setPixelColor(i, modul_led_ring.Color(color[0],color[1],color[2])); // Pixel 0 leuchtet in der RGB-Farbe Rot
    delay(1000);
    modul_led_ring.show();
  }
  for(int i = 0; i < 12; ++i){
    modul_led_ring.setPixelColor(i, modul_led_ring.Color(0,0,0)); // Pixel 0 leuchtet in der RGB-Farbe Rot
    delay(1000);
    modul_led_ring.show();
  }


 


  modul_led_ring.show(); // Anzeigen der Pixelfarben auf dem WS2812B LED Ring
}