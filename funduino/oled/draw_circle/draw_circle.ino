#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128, 64, &Wire, -1);
long randNumber;

void setup() {
  randomSeed(analogRead(0));
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
  }
  
  display.clearDisplay(); 
  display.drawCircle(63, 31, 10, WHITE);
  display.display();

}

void loop() {
  randNumber = random(0, 128);
  for(int i=0; i<30; i++)
  {
      display.drawCircle(randNumber, randNumber/2, i, WHITE);
      display.display();
  }
  display.clearDisplay(); 
  display.display();
}
