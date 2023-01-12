#include <switch.h>

Switch::Switch(byte sw_pin) {
    this->_sw_pin = sw_pin; // if the parameter name of the constructor is identical to 
                        // the attribute name, you can use this-> operator
    pinMode(this->_sw_pin, INPUT_PULLUP);
}

Switch::Status Switch::check() {
    Switch::Status status = RELEASED;

    if (digitalRead(_sw_pin) == LOW) {
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
