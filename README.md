# Arunduino
## 11月3日
### 來回燈
```C++
void setup() {
  for (int i=2; i<=9; i++)//設輸出腳位2~9,並都不亮
  {
  pinMode(i, OUTPUT);
  digitalWrite(i, 1);
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

