int ledPins[] = {3, 5, 6, 9, 10, 11};
int ledStates[] = {LOW, LOW, LOW, LOW, LOW, LOW};

long intervals[] = {60, 900, 1200, 15000, 80000, 210000};
long previousIntervals[] = {0, 0, 0, 0, 0, 0};
long currentMillis;

void setup() {
  DDRD = B01101000;
  DDRB = B00001110;
}

void loop() {
  for (int i = 0; i < 6; i++)
  {
    currentMillis = micros();
    if (currentMillis - previousIntervals[i] >= intervals[i]) {
      previousIntervals[i] = currentMillis;

      if (ledStates[i] == LOW) {
        ledStates[i] = HIGH;
      } else {
        ledStates[i] = LOW;
      } 
      if (ledStates[i]) {
        switch(ledPins[i]) {
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
        switch(ledPins[i]) {
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
  }
}
