int x=5;
int y=5;
int z=1;
void setup() {
  // put your setup code here, to run once:
   int i;
      for(i=9;i<12;i++)
        pinMode(i,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    if (x>=255 || x<=0)
   {
    y=-y;
   }
    x=x+y;
    switch(z)
    {
      case 1 : RGB(x,0,0);
      delay(20);
      break;
      case 2 : RGB(0,x,0);
      delay(20);
      break;
      case 3 : RGB(0,0,x);
      delay(20);
      break;
      case 4 :
      z=1;
      break;
    }
    if (x==5 && y >0)
   {
 z=z+1;
   }
    delay(10);
}

void RGB(int r, int g, int b)
{analogWrite(9,r);
 analogWrite(10,g);
 analogWrite(11,b);}
