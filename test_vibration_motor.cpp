#include <Arduino.h>

#define VIRATE_MOTOR 13

void vibrate(void *parameter) {
  while (1) {
    digitalWrite(VIRATE_MOTOR, HIGH);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    digitalWrite(VIRATE_MOTOR, LOW);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void setup() {
  pinMode(VIRATE_MOTOR, OUTPUT);

  xTaskCreate(
    vibrate,
    "Vibrate",
    1024,
    NULL,
    1,
    NULL
  );
}

void loop() {

}