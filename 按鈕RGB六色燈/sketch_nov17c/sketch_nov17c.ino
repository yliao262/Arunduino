   int x=0;
   int y=0;
void setup() {   
   pinMode(2, INPUT);
  for(int i=9 ;i<12 ;i++)
  {
   pinMode(i,OUTPUT );
  }
 
}

void loop() 
{
   if (digitalRead(2)==0)//按一下動一次
  {
    delay(200);    
    y=y+1;
  } 
  switch (y)
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
