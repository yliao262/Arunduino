# Arunduino
## 11月3日
### 來回燈
```C++
void setup() {
  for (int i=2; i<=10; i++)
  {
  pinMode(i, OUTPUT);//設輸出腳位2~10
  digitalWrite(i, 1);
  }
  
}

void loop() {
  for ( int i=2; i<=10; i++)//從2亮到10
  {
  digitalWrite(i, LOW);  
  delay(20); 
  digitalWrite(i, HIGH);  
  delay(20);                                     
  }    
  for ( int i=10; i>=2; i--)//從10亮到2
  {
  digitalWrite(i, LOW);  
  delay(20); 
  digitalWrite(i, HIGH);  
  delay(20);                                     
  }          
}
```
#### 功能：使LED來回移動(2~9)(9~2)
### 平交道燈
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
#### 功能：使LED來回亮(O 1_1 O 到 1 O_O 1),並在切換狀態時,使蜂鳴器叫。(O=亮, 1=不亮)
## 11月10日
### 按鈕控制LED
```C++  
int x=0;
void setup() {
  pinMode(2, INPUT);//輸入腳位2
  pinMode(3, OUTPUT);//輸出腳位3~6
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  digitalWrite(3, HIGH);//輸出腳位3~6,都不亮    
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
}

void loop() {

  switch (x)
  {
    case 0 :
      digitalWrite(3, HIGH);//LED全滅
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);    
    break;
    case 1 :
      digitalWrite(3, LOW);//x=1時,腳位3之LED亮
    break;
    case 2 :
      digitalWrite(4, LOW);//x=2時,腳位4之LED亮
    break;
    case 3 :
      digitalWrite(5, LOW);//x=3時,腳位5之LED亮
    break; 
    case 4 :
      digitalWrite(6, LOW);//x=4時,腳位6之LED亮
    break; 
  }
  if (digitalRead(2)==0)//當按下按鈕時x+1(x大於4時歸零)
  {
    delay(200);
    x= x+1;
    if(x>4)
    x=0;
  }

  } 
```
#### 功能：當按下按鈕時,LED依序亮(1111--0111--0011--0001--0000--1111)(0=亮,1=不亮)
#### 當前溫度(>=)29度
![](https://github.com/yliao262/Arunduino/blob/main/%E6%8C%89%E9%88%95LED%E5%BD%B1/MOV_0513.mp4)
## 11月17日
### 按鈕控制RGB燈
```C++
int x=0;
int y=0;
void setup() {   
   pinMode(2, INPUT);
  for(int i=9 ;i<12 ;i++)//設輸出腳位9~12
  {
   pinMode(i,OUTPUT );
  }
 
}

void loop() 
{
   if (digitalRead(2)==0)//按一次按鈕,y+1
  {
    delay(200);    
    y=y+1;
  } 
  switch (y)//依據y的數值亮各種RGB的顏色
  {
    case 0 :
      RGB(0,0 ,0);  
    break;
    case 1 :  
     RGB(50,0 ,0);  
    break;
    case 2 :
     RGB(0,50 ,0);
    break;
    case 3 :   
     RGB(0,0 ,50);
    break; 
    case 4 :
     RGB(50,50 ,0);
    break; 
    case 5 :
     RGB(0,50 ,50);
    break; 
    case 6 :
     RGB(50,0 ,50);
    break; 
    case 7 :
     y=0;
    break; 
  }          
}
void RGB (int r,int g,int b)
{
            //(腳位,RGB值)
   analogWrite(9,r);//R
   analogWrite(10,g);//G
   analogWrite(11,b);//B  
}
```
#### 功能：按按鈕(使y數值改變),依y之數值亮各種顏色的燈
## 11月24日
### 從0到9999(七段顯示)
```C++
const boolean data[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0 (七段顯示的數字0~9)
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}, // 9
};
byte seg[7] = {2,3,4,5,6,7,8};//輸出腳位2~8(七段)(a,b,c,d,e,f,g)
byte scan[4] = {12,11,10,9};//輸出腳位9~12(com)
byte number[4];
void setup() {
  for(int i=0;i<7;i++)
    pinMode(seg[i],OUTPUT);  
  for(int i=0;i<4;i++)
    pinMode(scan[i],OUTPUT);  
}

unsigned long oldtime=millis();//時間存檔點(開機時的時間)(第0秒)
int i=0;
void loop() {
  if(millis()-oldtime>=300)//當下時間-時間存檔點>300毫秒時,i+1(i>9999時,i歸零),時間存檔點更新為當下時間
    {
      oldtime = millis();
      i++;
      if(i>9999)
        i = 0;
    }
  number[3]= i /1000;//千位
  number[2]= (i - number[3] * 1000) / 100;//百位
  number[1]= (i - number[3] * 1000-number[2]*100) / 10;//十位
  number[0]= i % 10;//個位
  for(int j= 3;j>0;j--)
    Serial.print(number[j]);
  Serial.println('.');    
  for(int j=0;j<4;j++)
    { 
      disp(number[j]); //j=(個十百千)(com)           
      digitalWrite(scan[j],HIGH);//(com)
      delay(5);
      digitalWrite(scan[j],LOW);//(com)          
     } 
}

void disp(int num)
{
  for(int i=0;i<7;i++)
    digitalWrite(seg[i],data[num][i]);//顯示數字
}
```
#### 功能：啟動時從0顯示到9999後重來
## 12月1日
### RC馬達
```C++
#include <Servo.h>
Servo myservo;
int x = 0;
void setup()
{  
   pinMode(7, OUTPUT);
   pinMode(6, OUTPUT);
   pinMode(5, OUTPUT);
   pinMode(2, OUTPUT);
  myservo.attach(9); 
}

void loop() 
{  
     if (digitalRead(3)==0)
   {
    while(digitalRead(3)==0)
    {
      
     }
      x= x+1;
      if (x>4)
      {
       x=0; 
   }
    }

   switch (x)
   {
     case 0 :
      pinMode(2, LOW);
      pinMode(6, LOW);
      pinMode(7, LOW);
      pinMode(5, LOW);
      delay(50);
     break; 
     case 1 :
      myservo.write(180);//(hz)(數值越高越快)
      pinMode(2, HIGH);//LED
      delay(50);
     break;
     case 2 :
      myservo.write(150);
      pinMode(5, HIGH);//LED
      delay(50);
     break;
     case 3 :
      myservo.write(120);
      pinMode(6, HIGH);//LED
      delay(50);
     break;
     case 4 :
      myservo.write(90);
      pinMode(7, HIGH);//LED
      delay(50);
     break;
    
   }
}
```
#### 功能：按鈕可控制速度,快到慢(4種速度)
## 12月8日
### 按鈕控制風扇
```C++
int IN=0;
int OUT=0;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:// 4  6  7  8  10  
  pinMode(2,OUTPUT);//3  (類比輸出)
  pinMode(3,OUTPUT);//2
  pinMode(9,OUTPUT);//1
  pinMode(4,OUTPUT);//LED
  pinMode(6,OUTPUT);//LED
  pinMode(7,OUTPUT);//LED
  pinMode(8,OUTPUT);//LED
  pinMode(10,OUTPUT);//LED
  pinMode(5,INPUT);//button1
  pinMode(11,INPUT);//button2
}

void loop() {
 
 while(digitalRead(11)==0){
   
   if (digitalRead(11)==0) { //button2按下時,OUT+1(OUT>1,OUT歸零)(此按鈕視為電源開關)
      delay(250);
      OUT++;
      if (OUT>1)
      {
        OUT=0;
      }
    }
    else {digitalWrite(4, HIGH);}
    Serial.print("IN = ");
  Serial.println(IN);
   }
  if (OUT==1)  //(電源開啟)
  {
   while(digitalRead(5)==0){
   
   if (digitalRead(5)==0) { //button1按下時,IN+1(IN>4,IN歸零)(此按鈕可控制速度,從慢到快)(共有4種速度)
      digitalWrite(4, LOW);
      delay(250);
      IN++;
      if (IN>4)
      {
        IN=0;
      }
    }
    else {digitalWrite(4, HIGH);}
    Serial.print("IN = ");
  Serial.println(IN);
   }
    
    switch (IN){ //各種速度
      case 0:
       R (130);
       digitalWrite(4, LOW);
       digitalWrite(6, HIGH);
       digitalWrite(7, HIGH);
       digitalWrite(8, HIGH);
       digitalWrite(11, HIGH);
      break;
      case 1:
       R (150);
       digitalWrite(6, LOW);
      break;
      case 2:
       R (180);
       digitalWrite(7, LOW);

      break;
      case 3:
       R (220);
       digitalWrite(8, LOW);

      break;
      case 4:
       R (255);
       digitalWrite(11, LOW);

      break;
    }
  }
  if (OUT==0)/////
  {
    S();
    digitalWrite(4, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(10, HIGH);
  }
}
void R (int r)
{
  analogWrite(2,0);//3  (類比訊號可用之腳位數字旁需有(~),例：~2,~3,~9 等)
  analogWrite(3,0);//2
  analogWrite(9,r);//1
  
}
```
#### 功能：button2(電源)可開關風扇,button1(控速鈕)可控速
## 12月15日
### 液晶螢幕顯示
```C++
 /*
  The circuit:  //相關資訊
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 */
// include the library code:

#include <LiquidCrystal.h>
int x= 0;
String a[]={"A","B","C","D"};//上到下的陣列
String b[]={"C","D","A","B"};//下到上的陣列
int b1= 0;
int b2= 0;
int c1= 0;
int c2= 0;
int d= 1;
               // initialize the library by associating any needed LCD interface pin
               // with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.

}

void loop() {
  if(x==0)
  {
      lcd.setCursor(0, 0); //啟動時顯示"welcome"
      lcd.print("welcome");
    if(digitalRead(7)==0)
  {
    lcd.clear(); //按按鈕後,清除文字,顯示 "A" "B"
    while(digitalRead(7)==0)
    x=1;
  }
    if(digitalRead(8)==0)
  {
    lcd.clear();  //按按鈕後,清除文字,顯示 "A" "B"
    while(digitalRead(8)==0)
    x=1;
  }
  }
  if(x==1)
  { 
  if(digitalRead(7)==0)//加
  {
    d=1;
    lcd.clear();
    while(digitalRead(7)==0)
    delay(500);
    b1++;
    c1=0;
    if(b1>2)
    {
      b1=-1;
      c1=1;}
  }
  if(d==1)
  {
  if(c1<1)
  {
      lcd.setCursor(0, 0);
      lcd.print(a[b1]);
      lcd.setCursor(0, 1);
      lcd.print(a[b1+1]);
  }
  else
  {
      lcd.setCursor(0, 0);
      lcd.print(a[3]);
      lcd.setCursor(0, 1);
      lcd.print(a[0]);
  }
  }
      if(digitalRead(8)==0)//減
  {
    d=2;
    lcd.clear();
    while(digitalRead(8)==0)
    delay(500);
    b1--;
    c2=0;
    if(b1<0)
    {
      b1=3;
      c2=1;}
  }
    if(d==2)
  {
  if(c2<1)
  {
      lcd.setCursor(0, 0);
      lcd.print(a[b1]);
      lcd.setCursor(0, 1);
      lcd.print(a[b1+1]);
  }
  else
  {
      lcd.setCursor(0, 0);
      lcd.print(a[3]);
      lcd.setCursor(0, 1);
      lcd.print(a[0]);
  }
  }
  }
}
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  // print the number of seconds since reset://lcd.print(millis() / 1000);
```
#### 功能：按鈕(加)可使ABCD由上到下顯示.按鈕(減)可使ABCD由下到到顯示  (按一次變化一次)
## 12月29日
### 溫溼度感應器+燈
```C++
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#define DHTPIN 3
#define DHTTYPE    DHT22 
DHT_Unified dht(DHTPIN, DHTTYPE);
uint32_t delayMS;
void setup() {
  pinMode(2,OUTPUT);
  Serial.begin(9600);
  dht.begin();
  sensor_t sensor;
  delayMS = sensor.min_delay / 1000;
}

void loop() {
  delay(1000);
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println(F("Error reading temperature!"));
  }
  else {
    Serial.print(F("Temperature: "));
    Serial.print(event.temperature);
    Serial.println(F("°C"));
  }
  if(event.temperature>=27 && event.temperature<=29 )
  {
    digitalWrite(2,LOW);
  }
  else
  {
    digitalWrite(2,HIGH);
  }
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    Serial.println(F("Error reading humidity!"));
  }
  else {
    Serial.print(F("Humidity: "));
    Serial.print(event.relative_humidity);
    Serial.println(F("%"));
  }      
}
```
#### 功能：溫度(>=)27度並(<=)29度時燈會亮 否則不亮
#### 當前溫度(>=)29度
![](https://github.com/yliao262/Arunduino/blob/main/%E6%BA%AB%E6%BA%BC%E5%BA%A6%E5%9C%96/DSC_0526.JPG)
#### 當前溫度(<=)27度
![](https://github.com/yliao262/Arunduino/blob/main/%E6%BA%AB%E6%BA%BC%E5%BA%A6%E5%9C%96/DSC_0528.JPG)
#### 當前溫度(<=)29度
![](https://github.com/yliao262/Arunduino/blob/main/%E6%BA%AB%E6%BA%BC%E5%BA%A6%E5%9C%96/DSC_0525.JPG)
#### 當前溫度(<=)27度
![](https://github.com/yliao262/Arunduino/blob/main/%E6%BA%AB%E6%BA%BC%E5%BA%A6%E5%9C%96/DSC_0527.JPG)
