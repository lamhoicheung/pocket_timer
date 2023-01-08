#include <Arduino.h>

const byte CLK_PIN = 26;
const byte DT_PIN = 27;
int counter = 0;
bool clk_state = 0;
bool prev_clk_state = 0;

void setup() {
  Serial.begin(115200);
  pinMode(CLK_PIN, INPUT);
  pinMode(DT_PIN, INPUT);

  prev_clk_state = digitalRead(CLK_PIN);
}

void loop() {
  clk_state = digitalRead(CLK_PIN);

  if (clk_state != prev_clk_state && clk_state == 1) { // if CLK rising
    if (digitalRead(DT_PIN) != clk_state) {
      counter++;
    } else {
      counter--;
    }
    Serial.printf("Counter:%d\n", counter);
  }
  prev_clk_state = clk_state;
}