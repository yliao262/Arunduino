# Arunduino
## 11月3日
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
### 按鈕控制LED(繼電器)
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
