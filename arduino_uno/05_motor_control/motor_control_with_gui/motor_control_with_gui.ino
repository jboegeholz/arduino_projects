
const byte SPEED_RIGHT_MOTOR = 6;

const byte RIGHT_MOTOR_PIN1 = 7;
const byte RIGHT_MOTOR_PIN2 = 8;


void setup()
{
    //This sets frequency as 7812.5 hz.
    //TCCR0B = TCCR0B & B11111000 | B00000010;
    TCCR0B = TCCR0B & 0b11111000 | 0x01; 
    
    pinMode(SPEED_RIGHT_MOTOR, OUTPUT);
    pinMode(RIGHT_MOTOR_PIN1, OUTPUT);
    pinMode(RIGHT_MOTOR_PIN2, OUTPUT);

    digitalWrite(RIGHT_MOTOR_PIN1, HIGH);
    digitalWrite(RIGHT_MOTOR_PIN2, LOW);
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
    analogWrite(SPEED_RIGHT_MOTOR, 0);
}
void forward()
{
    digitalWrite(RIGHT_MOTOR_PIN1, HIGH);
    digitalWrite(RIGHT_MOTOR_PIN2, LOW);
}
void backwards()
{
    digitalWrite(RIGHT_MOTOR_PIN1, LOW);
    digitalWrite(RIGHT_MOTOR_PIN2, HIGH);
}
void drive(byte speed)
{
    analogWrite(SPEED_RIGHT_MOTOR, speed);
}

