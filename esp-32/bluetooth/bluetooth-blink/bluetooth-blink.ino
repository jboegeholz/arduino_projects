 #include "BluetoothSerial.h"
    
BluetoothSerial bt_serial;
String command = "";

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  bt_serial.begin("ESP32"); 
  Serial.println("ESP32 ready - you may now connect to this device");
}

void loop() {

  if (bt_serial.available()) {
    command = bt_serial.readStringUntil('\n');
    Serial.println(command);
    if(command == "On"){
      digitalWrite(LED_BUILTIN, HIGH);
    } else if(command == "Off"){
      digitalWrite(LED_BUILTIN, LOW);
    }  
  }
  delay(25);
}