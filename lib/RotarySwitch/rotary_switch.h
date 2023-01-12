#include <switch.h>

class RotarySwitch {
    private:
        byte _clk_pin;
        byte _dt_pin;
        bool _clk_state = 0;
        bool _prev_clk_state = 0;
        Switch* switchPtr = nullptr;

    public:
        typedef enum {
            RELEASED,
            PRESSED,
            RELEASED_FROM_PRESS,
            TURN_LEFT,
            TURN_RIGHT
        } Status;

        Status status = RELEASED;

        // constructor
        RotarySwitch(byte clk_pin, byte dt_pin, byte sw_pin) {
            _clk_pin = clk_pin;
            _dt_pin = dt_pin;
            switchPtr = new Switch(sw_pin);

            pinMode(_clk_pin, INPUT);
            pinMode(_dt_pin, INPUT);

            _prev_clk_state = digitalRead(_clk_pin);
        }

        Status check() {
            Status switch_status = (Status) switchPtr->check();

            _clk_state = digitalRead(_clk_pin);

            if (_clk_state != _prev_clk_state && _clk_state == 1) { // if CLK rising
                if (digitalRead(_dt_pin) != _clk_state) {
                    status = TURN_LEFT;
                } else {
                    status = TURN_RIGHT;
                }
            } else {
                status = RELEASED;
            }
            _prev_clk_state = _clk_state;

            if (switch_status != RELEASED) {
                status = switch_status;
            }

            return status;
        }
};