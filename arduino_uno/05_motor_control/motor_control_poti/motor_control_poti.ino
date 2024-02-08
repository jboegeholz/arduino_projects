const byte MOTOR_PWM = 6;
const byte MOTOR_PIN_1 = 7;
const byte MOTOR_PIN_2 = 8;
const byte POTI_IN = A0;

int potiValue = 0;
int motorSpeed = 0;
float factor = 0.249;


void setup() {

  TCCR0B = TCCR0B & B11111000 | B00000010;
  pinMode(MOTOR_PIN_1, OUTPUT);
  pinMode(MOTOR_PIN_2, OUTPUT);
  pinMode(MOTOR_PWM, OUTPUT);

  digitalWrite(MOTOR_PIN_1, LOW);
  digitalWrite(MOTOR_PIN_2, HIGH);
}

void loop() {

  potiValue = analogRead(POTI_IN);
  motorSpeed = (int)potiValue * factor;
  analogWrite(MOTOR_PWM, motorSpeed);// Then inject it to our motor
}
