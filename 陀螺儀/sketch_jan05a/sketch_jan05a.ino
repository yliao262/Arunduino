
int xpin = A1;                  //感測器 X_OUT 連接 Arduino pin A1
int ypin = A2;                  //感測器 Y_OUT 連接 Arduino pin A2
int zpin = A3;                  //感測器 Z_OUT 連接 Arduino pin A3

void setup()
{
 pinMode(2,OUTPUT);
 Serial.begin(9600);
 pinMode(3,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(5,OUTPUT);
}

void loop()
{
 int x = analogRead(xpin);  //讀 X 軸電壓值，存入整數 x  340.350  右大
 int y = analogRead(ypin);  //讀 Y 軸電壓值，存入整數 y  340.350  順大
 int z = analogRead(zpin);  //讀 Z 軸電壓值，存入整數 z

if(x<=350 && x>=340) //X
{
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
}
if(x>350)
{
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
}
if(x<340)
{
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
}                     //X
if(y<=350 && x>=340) //Y
{
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
}
if(y>350)
{
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
}
if(y<340)
{
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
}                     //Y

Serial.print("X ");
Serial.print(x);            //在序列埠螢幕中印出X Y Z的讀值
Serial.print("\t");
Serial.print("Y ");
Serial.print(y);
Serial.print("\t");
Serial.print("Z ");
Serial.print(z);  
Serial.print("\n");  
delay(500);
}
