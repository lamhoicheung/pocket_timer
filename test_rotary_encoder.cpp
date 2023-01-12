#include <Arduino.h>
#include <rotary_switch.h>


RotarySwitch rsw(26, 27, 14); // clk, dt, sw

void setup() {
  Serial.begin(115200);
}

void loop() {
  switch (rsw.check())
  {
    case RotarySwitch::RELEASED_FROM_PRESS:
      Serial.println("Release from press");
      break;

    case RotarySwitch::TURN_LEFT:
      Serial.println("Turn left");
      break;

    case RotarySwitch::TURN_RIGHT:
      Serial.println("Turn right");
      break;      
  
    default:
      break;
    }
}