#include <TaskManager.h>

int ledPins[] = {3, 5, 6, 9, 10, 11};
int ledStates[] = {LOW, LOW, LOW, LOW, LOW, LOW};
long intervals[] = {60, 900, 1200, 15000, 80000, 210000};

void setup() {
  DDRD = B01101000;
  DDRB = B00001110;
  
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
    
  if (ledState) {
    switch(led) {
      case 3:
        PORTD |= B00001000;
        break;
      case 5:
        PORTD |= B00100000;
        break;
      case 6:
        PORTD |= B01000000;
        break;
      case 9:
        PORTB |= B00000010;
        break;
      case 10:
        PORTB |= B00000100;
        break;
      case 11:
        PORTB |= B00001000;
        break;
    }
  }
  else {
    switch(led) {
      case 3:
        PORTD &= ~B00001000;
        break;
      case 5:
        PORTD &= ~B00100000;
        break;
      case 6:
        PORTD &= ~B01000000;
        break;
      case 9:
        PORTB &= ~B00000010;
        break;
      case 10:
        PORTB &= ~B00000100;
        break;
      case 11:
        PORTB &= ~B00001000;
        break;
    }
  }
}
