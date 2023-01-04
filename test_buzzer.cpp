#include <Arduino.h>

#define BUZZER 23

void buzz(void *parameter) {
  while (1) {
    tone(BUZZER, 300);
    vTaskDelay(200 / portTICK_PERIOD_MS);
    tone(BUZZER, 200);
    vTaskDelay(200 / portTICK_PERIOD_MS);
    noTone(BUZZER);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void setup() {
  pinMode(BUZZER, OUTPUT);

  xTaskCreate(
    buzz,
    "Buzz",
    1024,
    NULL,
    1,
    NULL
  );
}

void loop() {

}