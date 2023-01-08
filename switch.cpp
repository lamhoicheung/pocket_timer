#include <Arduino.h>

const byte LED_R = 33;
const byte SW = 14;

bool LED_state = 0;

uint32_t press_time = 0;
const uint8_t DEBOUNCE_TIME = 30;
const uint16_t LONG_PRESS_TIME = 500;
uint32_t last_hold_time = 0;
const uint8_t HOLD_TIME = 200;

bool is_pressed = false;
bool is_long_pressed = false;

typedef enum {
  RELEASED,
  PRESSED,
  LONG_PRESSED,
  PRESSING,
  RELEASED_FROM_PRESS,
  RELEASED_FROM_LONG_PRESS
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

    if (is_long_pressed && (millis() - last_hold_time > HOLD_TIME)) {
      status = PRESSING;
      last_hold_time = millis();
    }

    if (!is_long_pressed && (millis() - press_time > LONG_PRESS_TIME)) {
      is_long_pressed = true;
      status = LONG_PRESSED;
    }
  } else {
    if (is_pressed) {
      if (is_long_pressed) { // if long pressed, reset long press record
        is_long_pressed = false;
        last_hold_time = 0;
        status = RELEASED_FROM_LONG_PRESS;
      } else if ((millis() - press_time) > DEBOUNCE_TIME) {
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
  case LONG_PRESSED:
    LED_state = !LED_state;
    digitalWrite(LED_R, LED_state);
    break;
  
  default:
    break;
  }
}