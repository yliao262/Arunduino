Arunduino
## 11月3日
```C++
void setup() {
  for (int i=2; i<=9; i++)
  {
  pinMode(i, OUTPUT);
  digitalWrite(i, 1);
  }
  
}

void loop() {
  for ( int i=2; i<=9; i++)
  {
  digitalWrite(i, LOW);  
  delay(200); 
  digitalWrite(i, HIGH);  
  delay(200);                                     
  }    
  for ( int i=9; i>=2; i--)
  {
  digitalWrite(i, LOW);  
  delay(200); 
  digitalWrite(i, HIGH);  
  delay(200);                                     
  }          
}
```

