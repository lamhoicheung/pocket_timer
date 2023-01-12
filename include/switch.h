#include <Arduino.h> // if I comment this, still be able to compile with no errors

typedef enum {
  RELEASED,
  PRESSED,
  RELEASED_FROM_PRESS
} SW_Status;


class Switch {
  long _press_time = 0;
  const long _DEBOUNCE_TIME = 30;
  bool _is_pressed = false;

  public:
    byte sw_pin;

    Switch(byte sw_pin) {
      this->sw_pin = sw_pin; // if the parameter name of the constructor is identical to 
                            // the attribute name, you can use this-> operator
      pinMode(this->sw_pin, INPUT_PULLUP);
    }

    SW_Status check() {
      SW_Status status = RELEASED;

      if (digitalRead(sw_pin) == LOW) {
        if (!_is_pressed) { // record the press time when button is pressed
          _is_pressed = true;
          status = PRESSED;
          _press_time = millis();
        }
      } else {
        if (_is_pressed) {
          if ((millis() - _press_time) > _DEBOUNCE_TIME) {
            status = RELEASED_FROM_PRESS;
          }
          _is_pressed = false;
        }
      }

      return status;
    }
};
