/*
    Check switch status

    Author: Lukas
    Version: 20230112

*/

#ifndef SWITCH_H
#define SWITCH_H
#include <Arduino.h>

class Switch {
    private:
        byte _sw_pin;
        long _press_time = 0;
        const long _DEBOUNCE_TIME = 30;
        bool _is_pressed = false;

    public:
        typedef enum {
        RELEASED,
        PRESSED,
        RELEASED_FROM_PRESS
        } Status;

        Switch(byte sw_pin);
        Status check();
};

#endif