#include <DynamixelShield.h>


const uint8_t DXL_ID = 1;
const float DXL_PROTOCOL_VERSION = 2.0;
const uint16_t BAUDRATE = 57600; 
DynamixelShield dxl;



void setup() {

  
  dxl.begin(57600);

  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);

      if(dxl.ping(DXL_ID) == true){
          dxl.torqueOff(DXL_ID);
          dxl.setOperatingMode(DXL_ID, OP_VELOCITY);
          dxl.torqueOn(DXL_ID);
      }
}

void loop() {

  dxl.setGoalVelocity(DXL_ID, 200, UNIT_RAW);
  delay(1000);

  dxl.setGoalVelocity(DXL_ID, 25.8, UNIT_RPM);
  delay(1000);

  dxl.setGoalVelocity(DXL_ID, -10.2, UNIT_PERCENT);
  delay(1000);

}