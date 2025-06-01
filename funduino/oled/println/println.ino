#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 oled(128, 64, &Wire, -1);


void setup()
{   
    Wire.begin();
    oled.setFont(utf8font10x16);
    oled.begin(&Adafruit128x64, 0x3C);
}   

void loop()
{   
    oled.setFont(Arial14);
    fontTest();
    oled.setFont(Callibri11);
    fontTest();
    oled.setFont(Callibri11_bold);
    fontTest();
    oled.setFont(Callibri15);
    fontTest();
    oled.setFont(System5x7);
    fontTest();
    oled.setFont(TimesNewRoman13);
    fontTest();
    oled.setFont(TimesNewRoman16);
    fontTest();
    oled.setFont(utf8font10x16);
    fontTest();
    oled.setFont(X11fixed7x14);
    fontTest();


    oled.clear();
} 
void fontTest()
{ 
    oled.clearDisplay(); 
    oled.println("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    oled.println("BXXXXXXXXXXXXXXXXXXXX");
    oled.println("CXXXXXXXXXXXXXXXXXXXX");
    oled.println("DXXXXXXXXXXXXXXXXXXXX");
    oled.println("EXXXXXXXXXXXXXXXXXXXX");
    oled.println("FXXXXXXXXXXXXXXXXXXXX");
    oled.println("GXXXXXXXXXXXXXXXXXXXX");
    oled.println("HXXXXXXXXXXXXXXXXXXXX");
    
    delay(2000);
}