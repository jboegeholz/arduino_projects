#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128, 64, &Wire, -1);
long randNumber;

void setup() {

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
  }
  
  display.clearDisplay(); 
  display.display();

}

void loop() {

  for(int i=0; i<62; i++)
  {
      display.drawLine(61, 31, 61+i, 31+i/2, WHITE);
      display.display();
  }
  display.clearDisplay(); 
  display.display();
}
