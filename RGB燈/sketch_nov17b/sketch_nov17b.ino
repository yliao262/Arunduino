void setup() {
  for(int i=9 ;i<12 ;i++)
  {
   pinMode(i,OUTPUT );
  }
}

void loop() {
          //(腳位,RGB值)
  analogWrite(9,50);//R
  analogWrite(10,0);//G
  analogWrite(11,50);//B

}
