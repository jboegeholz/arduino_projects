#include <Wire.h>
#include <SSD1306Ascii.h>
#include <SSD1306AsciiWire.h>
SSD1306AsciiWire oled;

void setup ()
{
  Wire.begin();
  oled.setFont(System5x7);
  oled.begin(&Adafruit128x64, 0x3C);
}
void loop()
{
  oled.println("Hello ");
  oled.println("World!");
}