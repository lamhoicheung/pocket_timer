#include <Arduino.h>

int hour = 0;
int minute = 1;
int second = 12;

void showTime() {
  Serial.print(hour); Serial.print(':');
  Serial.print(minute); Serial.print(':');
  Serial.print(second); Serial.println();
}

void countup() {
  second++;

  if (second > 59) {
    second = 0;
    minute++;
  }

  if (minute > 59) {
    minute = 0;
    hour++;
  }

  if (hour > 99) {
    hour = 0;
  }

  delay(1000);
  showTime();
}

void countdown() {
  if (second == 0 && minute == 0 && hour == 0) {
    Serial.println("DONE");
    while(1);
  }

  second--;

  if (second < 0) {
    second = 59;
    minute--;
  }

  if (minute < 0) {
    minute = 59;
    hour--;
  }

  if (hour < 0) {
    hour = 0;
  }

  delay(1000);
  showTime();  
}


void setup() {
  Serial.begin(115200);
}

void loop() {
  countdown();
}