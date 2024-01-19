//This code is to control the speed of a DC motor by a potentiometer using l298n driver
//We read the value from the analog input, calibrate it then inject to the module
//Refer to Surtrtech youtube channel for more information
// Source: instructables.com/Control-DC-Motor-Speed-Using-Potentiometer-L298n-A/


int in1 = 8; //Declaring where our module is wired
int in2 = 9;
int ConA = 10;// Don't forget this is a PWM DI/DO
int speed1;

void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void TurnMotorA(){ //We create a function which control the direction and speed
  digitalWrite(in1, LOW); //Switch between this HIGH and LOW to change direction
  digitalWrite(in2, HIGH);
  speed1 = analogRead(A0);
  speed1 = speed1*0.2492668622; //We read thea analog value from the potentiometer calibrate it
  analogWrite(ConA,speed1);// Then inject it to our motor
}
void loop() {
TurnMotorA(); //one function that keeps looping you can add another one with different direction or stop

}
