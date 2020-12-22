# Arunduino
## 11月3日
### 來回燈
```C++
void setup() {
  for (int i=2; i<=9; i++)
  {
  pinMode(i, OUTPUT);//設輸出腳位2~9
  digitalWrite(i, 1);//一開始都不亮
  }
  
}

void loop() {
  for ( int i=2; i<=9; i++)
  {
  digitalWrite(i, LOW);//腳位i亮(2~9)
  delay(200); 
  digitalWrite(i, HIGH);//腳位i不亮
  delay(200);                                     
  }    
  for ( int i=9; i>=2; i--)
  {
  digitalWrite(i, LOW);//腳位i亮(9~2)
  delay(200); 
  digitalWrite(i, HIGH);//腳位i不亮
  delay(200);                                     
  }          
}
```
## 功能：使LED來回亮(從腳位2到9,再從9到2)。
### 平交道
```C++
int buzzerPin=9;

void setup() {
  for (int i=2; i<=5; i++)
  {
  pinMode(i, OUTPUT);//設輸出腳位2~5
  digitalWrite(i, HIGH);//一開始都不亮
  }
  pinMode(buzzerPin, OUTPUT);//蜂鳴器輸出腳位
}

void loop() {

  digitalWrite(2, LOW);//O 1_1 O 燈的狀態(O=亮, 1=不亮)
  digitalWrite(5, LOW);   
  alarmClockBeep(buzzerPin);//呼叫蜂鳴器
  delay(200);                       
  digitalWrite(2, HIGH);//1 1_1 1
  digitalWrite(5, HIGH);
  delay(200);   
  digitalWrite(3, LOW);//1 O_O 1
  digitalWrite(4, LOW);   
  alarmClockBeep(buzzerPin);//呼叫蜂鳴器
  delay(200); 
  digitalWrite(3, HIGH);//1 1_1 1
  digitalWrite(4, HIGH);    
  delay(200);                      
}

void alarmClockBeep(int pin) {

  tone(pin, 1000, 100);//tone(腳位, 頻率, 持續時間);
  delay(50);  
  }
```
## 功能：使LED來回亮(O 1_1 O 到 1 O_O 1),並在切換狀態時,使蜂鳴器叫。(O=亮, 1=不亮)
