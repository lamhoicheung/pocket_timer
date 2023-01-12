#include <Arduino.h>
#include <switch.h>

const byte LED_R = 33;
const byte SW_PIN = 14;

bool LED_state = 0;


Switch sw(SW_PIN);

void setup() {
  Serial.begin(115200);
  pinMode(LED_R, OUTPUT);
}

void loop() {
  switch (sw.check())
  {
  case RELEASED_FROM_PRESS:
    LED_state = !LED_state;
    digitalWrite(LED_R, LED_state);
    break;
  
  default:
    break;
  }
}