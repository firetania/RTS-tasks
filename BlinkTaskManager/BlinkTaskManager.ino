#include <TaskManager.h>

int ledPins[] = {3, 5, 6, 9, 10, 11};
int ledPinsLen = sizeof(ledPins);
int ledStates[] = {LOW, LOW, LOW, LOW, LOW, LOW};
//unsigned long previousMillis[] = {0, 0, 0, 0, 0, 0};
//long intervals[] = {60000, 90000, 120000, 150000, 180000, 210000};
long intervals[] = {60, 900, 1200, 15000, 80000, 210000};

void setup() {
  for (int i = 0; i < ledPinsLen; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  taskManager.scheduleFixedRate(intervals[0], [] {
    led(ledStates[0], ledPins[0]);
  }, TIME_MICROS);
      
  taskManager.scheduleFixedRate(intervals[1], [] {
    led(ledStates[1], ledPins[1]);
  }, TIME_MICROS);
      
  taskManager.scheduleFixedRate(intervals[2], [] {
    led(ledStates[2], ledPins[2]);
  }, TIME_MICROS);
      
  taskManager.scheduleFixedRate(intervals[3], [] {
    led(ledStates[3], ledPins[3]);
  }, TIME_MICROS);
      
  taskManager.scheduleFixedRate(intervals[4], [] {
    led(ledStates[4], ledPins[4]);
  }, TIME_MICROS);
      
  taskManager.scheduleFixedRate(intervals[5], [] {
    led(ledStates[5], ledPins[5]);
  }, TIME_MICROS);
}

void loop() {
  taskManager.runLoop();
}

void led(int &ledState, int led)
{
  if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
  digitalWrite(led, ledState);
}
