const int MOTOR_SPEED = 210;
const int DELTA = 45;

const int ENABLE_RIGHT_MOTOR = 6;
const int ENABLE_LEFT_MOTOR = 5;

const int RIGHT_MOTOR_PIN1 = 7;
const int RIGHT_MOTOR_PIN2 = 8;

const int LEFT_MOTOR_PIN1 = 9;
const int LEFT_MOTOR_PIN2 = 10;

const int IR_SENSOR_RIGHT = 11;
const int IR_SENSOR_LEFT = 12;

void setup()
{

    pinMode(ENABLE_RIGHT_MOTOR, OUTPUT);
    pinMode(RIGHT_MOTOR_PIN1, OUTPUT);
    pinMode(RIGHT_MOTOR_PIN2, OUTPUT);

    pinMode(ENABLE_LEFT_MOTOR, OUTPUT);
    pinMode(LEFT_MOTOR_PIN1, OUTPUT);
    pinMode(LEFT_MOTOR_PIN2, OUTPUT);

    pinMode(IR_SENSOR_RIGHT, INPUT);
    pinMode(IR_SENSOR_LEFT, INPUT);

}


void loop()
{

    int rightIRSensorValue = digitalRead(IR_SENSOR_RIGHT);
    int leftIRSensorValue = digitalRead(IR_SENSOR_LEFT);

    //If none of the sensors detects black line, then go straight
    if (rightIRSensorValue == LOW && leftIRSensorValue == LOW)
    {
        driveStraight();
    }
    //If right sensor detects black line, then turn right
    else if (rightIRSensorValue == HIGH && leftIRSensorValue == LOW )
    {
        turnRight();
    }
    //If left sensor detects black line, then turn left
    else if (rightIRSensorValue == LOW && leftIRSensorValue == HIGH )
    {
        turnLeft();
    }
    //If both the sensors detect black line, then stop
    else
    {
        stop();
    }
}

void stop()
{
    digitalWrite(LEFT_MOTOR_PIN1, LOW);
    digitalWrite(LEFT_MOTOR_PIN2, LOW);

    digitalWrite(RIGHT_MOTOR_PIN1, LOW);
    digitalWrite(RIGHT_MOTOR_PIN2, LOW);

    analogWrite(ENABLE_LEFT_MOTOR, 0);
    analogWrite(ENABLE_RIGHT_MOTOR, 0);
}

void driveStraight()
{
    digitalWrite(LEFT_MOTOR_PIN1, HIGH);
    digitalWrite(LEFT_MOTOR_PIN2,LOW);

    digitalWrite(RIGHT_MOTOR_PIN1, HIGH);
    digitalWrite(RIGHT_MOTOR_PIN2, LOW);

    analogWrite(ENABLE_LEFT_MOTOR, MOTOR_SPEED);
    analogWrite(ENABLE_RIGHT_MOTOR, MOTOR_SPEED);
}

void turnRight()
{
    digitalWrite(LEFT_MOTOR_PIN1, HIGH);
    digitalWrite(LEFT_MOTOR_PIN2,LOW);

    digitalWrite(RIGHT_MOTOR_PIN1, HIGH);
    digitalWrite(RIGHT_MOTOR_PIN2, LOW);

    analogWrite(ENABLE_LEFT_MOTOR, MOTOR_SPEED + DELTA);
    analogWrite(ENABLE_RIGHT_MOTOR, MOTOR_SPEED - DELTA);
}

void turnLeft()
{
    digitalWrite(LEFT_MOTOR_PIN1, HIGH);
    digitalWrite(LEFT_MOTOR_PIN2,LOW);

    digitalWrite(RIGHT_MOTOR_PIN1, HIGH);
    digitalWrite(RIGHT_MOTOR_PIN2, LOW);

    analogWrite(ENABLE_LEFT_MOTOR, MOTOR_SPEED - DELTA);
    analogWrite(ENABLE_RIGHT_MOTOR, MOTOR_SPEED + DELTA);
}