#include <Arduino.h>

#define LED_R 33
#define LED_G 32
#define LED_B 25

int led_mode = 0;

void led(void *parameter) {
  while (1) {
    switch (led_mode)
    {
    case 0:
      // flash
      digitalWrite(LED_R, HIGH);
      digitalWrite(LED_G, LOW);
      digitalWrite(LED_B, LOW);
      vTaskDelay(100 / portTICK_PERIOD_MS);

      digitalWrite(LED_R, LOW);
      digitalWrite(LED_G, HIGH);
      digitalWrite(LED_B, LOW);
      vTaskDelay(100 / portTICK_PERIOD_MS);

      digitalWrite(LED_R, LOW);
      digitalWrite(LED_G, LOW);
      digitalWrite(LED_B, HIGH);
      vTaskDelay(100 / portTICK_PERIOD_MS);

      digitalWrite(LED_R, LOW);
      digitalWrite(LED_G, LOW);
      digitalWrite(LED_B, LOW);
      vTaskDelay(1000 / portTICK_PERIOD_MS);
      break;

    case 1:
      // regular on
      digitalWrite(LED_R, LOW);
      digitalWrite(LED_G, HIGH);
      digitalWrite(LED_B, LOW);

    case 2:
      // charging
      digitalWrite(LED_R, HIGH);
      digitalWrite(LED_G, LOW);
      digitalWrite(LED_B, LOW);

    case 3:
      // off
      digitalWrite(LED_R, LOW);
      digitalWrite(LED_G, LOW);
      digitalWrite(LED_B, LOW);      

    default:
      break;
    }
  }
}

void setup() {
  pinMode(LED_R, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(LED_G, OUTPUT);

  xTaskCreate(
    led,
    "LED",
    1024,
    NULL,
    1,
    NULL
  );
}

void loop() {

}