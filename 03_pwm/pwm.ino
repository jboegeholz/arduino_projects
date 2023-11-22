// Define the pin for outputting the PWM signal
const int pwmPin = 9; // Use a PWM-capable pin

void setup() {
  // Initialize the PWM pin as an output
  pinMode(pwmPin, OUTPUT);
}

void loop() {
  // Create a loop to change brightness
  for (int brightness = 0; brightness <= 255; brightness++) {
    // Change the brightness (PWM value)
    analogWrite(pwmPin, brightness);

    // Wait for a while
    delay(10);
  }

  // Change the brightness in the reverse direction
  for (int brightness = 255; brightness >= 0; brightness--) {
    // Change the brightness (PWM value)
    analogWrite(pwmPin, brightness);

    // Wait for a while
    delay(10);
  }
}