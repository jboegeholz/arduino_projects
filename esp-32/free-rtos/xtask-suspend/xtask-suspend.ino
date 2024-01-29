#include <Arduino.h>

int count1 = 0;
int count2 = 0;

TaskHandle_t task1_handle = NULL;
TaskStatus_t xTaskDetails;
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
    task1,        //function
    "Task 1",     // function name
    1000,         // stack size
    NULL,         // paramters
    1,            // priority
    &task1_handle // handle
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
  vTaskGetInfo( task1_handle, &xTaskDetails, pdTRUE, eInvalid );
  if(count1 == 5 && task1_handle != NULL){
    Serial.println("Suspending Task 1");
    vTaskSuspend(task1_handle);
  }
  if(count2 == 12 && task1_handle != NULL){
    Serial.println("REsuming Task 1");
    vTaskResume(task1_handle);
  }
}
