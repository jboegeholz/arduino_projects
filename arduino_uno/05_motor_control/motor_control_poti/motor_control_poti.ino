const byte MOTOR_PIN_1 = 8;
const int MOTOR_PIN_2 = 9;
const int MOTOR_PWM = 10;
const int POTI_IN = A0;

int potiValue = 0;
int motorSpeed = 0;
float factor = 0.249;


void setup() {
  pinMode(MOTOR_PIN_1, OUTPUT);
  pinMode(MOTOR_PIN_2, OUTPUT);
  pinMode(MOTOR_PWM, OUTPUT);

  digitalWrite(MOTOR_PIN_1, LOW);
  digitalWrite(MOTOR_PIN_2, HIGH);
}

void loop() {

  potiValue = analogRead(A0);
  motorSpeed = (int)potiValue * factor;
  analogWrite(MOTOR_PWM, motorSpeed);// Then inject it to our motor
}
