int x=0;
void setup() {
  pinMode(3, OUTPUT);
  pinMode(2, INPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  digitalWrite(3, HIGH);    
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
}

void loop() {

 
  switch (x)
  {
    case 0 :
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);    
    break;
    case 1 :
    digitalWrite(3, LOW);
    
    break;
    case 2 :
    digitalWrite(4, LOW);

    break;
    case 3 :
   digitalWrite(5, LOW);

    break; 
    case 4 :
    digitalWrite(6, LOW);

    break; 
  }
  if (digitalRead(2)==0)
  {
    delay(200);
    x= x+1;
    if(x>4)
    x=0;
  }

  } 
