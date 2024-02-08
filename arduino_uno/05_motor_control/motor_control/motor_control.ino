const int MOTOR_PIN_1 = 8;
const int MOTOR_PIN_2 = 9;
const int MOTOR_PWM = 10;


void setup() {
  pinMode(MOTOR_PIN_1, OUTPUT);
  pinMode(MOTOR_PIN_2, OUTPUT);
  pinMode(MOTOR_PWM, OUTPUT);
  
  digitalWrite(MOTOR_PIN_1, LOW); 
  digitalWrite(MOTOR_PIN_2, HIGH);
}

void loop() {
  analogWrite(MOTOR_PWM, 255);
}
