int ledPins[] = {3, 5, 6, 9, 10, 11};
int ledPinsLen = sizeof(ledPins);
int ledStates[] = {LOW, LOW, LOW, LOW, LOW, LOW};
unsigned long previousMillis[] = {0, 0, 0, 0, 0, 0};
//long intervals[] = {60000, 90000, 120000, 150000, 180000, 210000};
long intervals[] = {60, 900, 1200, 15000, 80000, 210000};
unsigned long currentMillis;

void setup() {
  for (int i = 0; i < ledPinsLen; i++){
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  currentMillis = micros();
  for (int i = 0; i < 6 ; i++){    
    if (currentMillis - previousMillis[i] >= intervals[i]) {
      previousMillis[i] = currentMillis;
  
    if (ledStates[i] == LOW) {
      ledStates[i] = HIGH;
    } else {
      ledStates[i] = LOW;
    } 
      
    digitalWrite(ledPins[i], ledStates[i]);
    }
  }
}
