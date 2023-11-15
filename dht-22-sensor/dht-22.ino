#include "DHT.h"



float temp;
float humidity;

DHT dht(4, DHT22);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {

  temp = dht.readTemperature();
  humidity = dht.readHumidity();

  Serial.print("Temperatur: ");
  Serial.print(temp);
  Serial.println(" *C");
  Serial.print("Luftfeuchtigkeit: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.println();
  delay(2000);

}