#include <Arduino.h>

const byte LED_R = 33;
const byte SW = 14;

bool LED_state = 0;

uint32_t press_time = 0;
const uint8_t DEBOUNCE_TIME = 30;

bool is_pressed = false;

typedef enum {
  RELEASED,
  PRESSED,
  RELEASED_FROM_PRESS
} SW_Status;

SW_Status checkSwitch(byte pin, bool ON = HIGH, bool pullup = false) {

  SW_Status status = RELEASED;
  
  if (pullup) {
    pinMode(pin, INPUT_PULLUP);
  } else {
    pinMode(pin, INPUT);
  }

  if (digitalRead(pin) == ON) {
    if (!is_pressed) { // record the press time when button is pressed
      is_pressed = true;
      status = PRESSED;
      press_time = millis();
    }
  } else {
    if (is_pressed) {
      if ((millis() - press_time) > DEBOUNCE_TIME) {
        status = RELEASED_FROM_PRESS;
      }
      is_pressed = false;
    }
  }

  return status;
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_R, OUTPUT);
}

void loop() {
  switch (checkSwitch(SW, LOW, true))
  {
  case RELEASED_FROM_PRESS:
    LED_state = !LED_state;
    digitalWrite(LED_R, LED_state);
    break;
  
  default:
    break;
  }
}