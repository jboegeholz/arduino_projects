const byte P_FET_Q1 = 2;
const byte N_FET_Q4 = 3; // PWM controlled
const byte P_FET_Q3 = 8;
const byte N_FET_Q2 = 9; // PWM controlled

byte current_PWM_port = N_FET_Q4;

void setup()
{
    //This sets frequency as 7812.5 hz.
    //TCCR0B = TCCR0B & B11111000 | B00000010;
    TCCR0B = TCCR0B & 0b11111000 | 0x01; 
    
    pinMode(P_FET_Q1, OUTPUT);
    pinMode(N_FET_Q2, OUTPUT);
    pinMode(P_FET_Q3, OUTPUT);
    pinMode(N_FET_Q4, OUTPUT);

    Serial.begin(9600);

}


void loop()
{
 if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');

    if (cmd.startsWith("PWM:")) {
      int value = cmd.substring(4).toInt();
      if (value < 0) {
        backwards();
        value = -value;
      } else {
        forward();
      }
      value = constrain(value, 0, 255);
      drive(value);
    } else if (cmd == "STOP") {
      stop();
    }
  }

}

void stop()
{
    analogWrite(current_PWM_port, 0);
}
void forward()
{
    digitalWrite(P_FET_Q1, HIGH);
    digitalWrite(P_FET_Q3, LOW);
    current_PWM_port = N_FET_Q4;

}
void backwards()
{
    digitalWrite(P_FET_Q1, LOW);
    digitalWrite(P_FET_Q3, HIGH);
    current_PWM_port = N_FET_Q2;
}
void drive(byte speed)
{
    analogWrite(current_PWM_port, speed);
}

