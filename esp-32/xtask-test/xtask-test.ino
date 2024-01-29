#include <Arduino.h>

int count1 = 0;
int count2 = 0;

void task1(void* parameters){
  for(;;){
    Serial.print("Task 1 counter: ");
    Serial.println(count1++);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void task2(void* parameters){
  for(;;){
    Serial.print("Task 2 counter: ");
    Serial.println(count2++);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void setup() {
  Serial.begin(9600);
  xTaskCreate(
    task1,      //function
    "Task 1",   // function name
    1000,       // stack size
    NULL,       // paramters
    1,          // priority
    NULL        // handle
  );
  xTaskCreate(
    task2,
    "Task 2",
    1000,
    NULL,
    1,
    NULL
  );
}

void loop() {
  // put your main code here, to run repeatedly:

}
