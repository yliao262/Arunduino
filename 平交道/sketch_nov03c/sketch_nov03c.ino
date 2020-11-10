
int buzzerPin=9;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {

  
  
  digitalWrite(2, LOW);//digitalWrite(2, LOW/HIGH/0/1);
  digitalWrite(5, LOW);   
  alarmClockBeep(buzzerPin);
  delay(200);                       
  digitalWrite(2, HIGH); 
  digitalWrite(5, HIGH);
  alarmClockBeep(buzzerPin);
  delay(200);   
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW);   
  alarmClockBeep(buzzerPin);
  delay(200); 
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);    
  alarmClockBeep(buzzerPin);
  delay(200);
                      
}

void alarmClockBeep(int pin) {
  tone(pin, 1000, 100);//tone(pin, 頻率, 時間);
  delay(50);
  
  }
