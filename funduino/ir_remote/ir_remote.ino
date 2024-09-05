// use lib version 2.0.1
#include <IRremote.h>


int modul_infrarotSensor = 2;
decode_results werte;

IRrecv infrarotEmpfaenger(modul_infrarotSensor);


void setup()
{
  Serial.begin(9600);
  infrarotEmpfaenger.enableIRIn();
}


void loop()
{
  if (infrarotEmpfaenger.decode(&werte))
  {
    switch (werte.value) {
      case 16769055:
        Serial.println("0 received");
        break;
      case 16738455:
        Serial.println("1 received");
        break;
      case 16750695:
        Serial.println("2 received");
        break;
      case 16756815:
        Serial.println("3 received");
        break;
      case 16724175:
        Serial.println("4 received");
        break;
      case 16718055:
        Serial.println("5 received");
        break;
      case 16743045:
        Serial.println("6 received");
        break;
      case 16716015:
        Serial.println("7 received");
        break;
      case 16726215:
        Serial.println("8 received");
        break;
      case 16734885:
        Serial.println("9 received");
        break;

      default:
        Serial.println(werte.value, DEC);

    }
    infrarotEmpfaenger.resume();

  }
}
