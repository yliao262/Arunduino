
int buzzerPin=9;

void setup() {
 pinMode(buzzerPin, OUTPUT);
 }

void loop() {
  alarmClockBeep(buzzerPin);  
  }

void alarmClockBeep(int pin) {
  tone(pin, 2200, 100);
  delay(200);
  
  }
