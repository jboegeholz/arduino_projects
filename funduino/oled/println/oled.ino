#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display(128, 64, &Wire, -1);
void setup ()
{
  Wire.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}
void loop()
{
  display.println("Joern ");
  display.println("Boegeholz");
}