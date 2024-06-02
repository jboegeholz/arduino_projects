#include <Adafruit_NeoPixel.h> // Einbindung der Adafruit_Neopixel.h Bibliothek
#define PIN 4 // An welchem digitalen Pin ist der WS2812B Ring mit dem Mikrocontroller verbunden
#define NUMPIXELS 12 // Über wie viele Pixel verfügt der WS2812B Ring?

Adafruit_NeoPixel modul_led_ring = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800); // Konfiguration des Objektes modul_led_ring

int color[3]      = {80,10,88};

void setup()
{
  modul_led_ring.begin(); // Initialisierung des WS2812B LED Rings
  modul_led_ring.show();
}

void loop()
{

  modul_led_ring.setPixelColor(0, modul_led_ring.Color(color[0],color[1],color[2])); // Pixel 0 leuchtet in der RGB-Farbe Rot
  modul_led_ring.setPixelColor(1, modul_led_ring.Color(color[0],color[1],color[2])); // Pixel 0 leuchtet in der RGB-Farbe Rot
  modul_led_ring.setPixelColor(2, modul_led_ring.Color(color[0],color[1],color[2])); // Pixel 0 leuchtet in der RGB-Farbe Rot
  modul_led_ring.setPixelColor(3, modul_led_ring.Color(color[0],color[1],color[2])); // Pixel 0 leuchtet in der RGB-Farbe Rot


  modul_led_ring.setPixelColor(4, modul_led_ring.Color(0,12,0)); // Pixel 4 leuchtet in der RGB-Farbe Grün
  modul_led_ring.setPixelColor(5, modul_led_ring.Color(0,12,0)); // Pixel 5 leuchtet in der RGB-Farbe Grün
  modul_led_ring.setPixelColor(6, modul_led_ring.Color(0,12,0)); // Pixel 6 leuchtet in der RGB-Farbe Grün
  modul_led_ring.setPixelColor(7, modul_led_ring.Color(0,12,0)); // Pixel 7 leuchtet in der RGB-Farbe Grün

  modul_led_ring.setPixelColor(8, modul_led_ring.Color(0,0,12)); // Pixel 8 leuchtet in der RGB-Farbe Blau
  modul_led_ring.setPixelColor(9, modul_led_ring.Color(0,0,12)); // Pixel 9 leuchtet in der RGB-Farbe Blau
  modul_led_ring.setPixelColor(10, modul_led_ring.Color(0,0,12)); // Pixel 10 leuchtet in der RGB-Farbe Blau
  modul_led_ring.setPixelColor(11, modul_led_ring.Color(0,0,12)); // Pixel 11 leuchtet in der RGB-Farbe Blau


  modul_led_ring.show(); // Anzeigen der Pixelfarben auf dem WS2812B LED Ring
}