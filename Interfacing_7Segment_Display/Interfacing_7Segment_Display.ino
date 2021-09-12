//Interfacing a seven segment display into Arduino
//Common anode seven segment display
//Date: 21-08-2021
//Yash Agrawal

const int pinA = 2;
const int pinB = 3;
const int pinC = 4;
const int pinD = 5;
const int pinE = 6;
const int pinG = 7;
const int pinF = 8;
const int dTime = 3000;

void setup()
{
  for(int i = 0; i <=8; i++)
  {
    pinMode(i,OUTPUT);
  }
}

void loop()
{
  //Making all the segments dim in the start
  for(int i = 2; i <= 8; i++)
  {
    digitalWrite(i,HIGH);
  }
  
  //Making the single segments of the display glow at once.
  for(int i = 2; i <= 8; i++)
  {
    digitalWrite(i,LOW);
    delay(1000);
    digitalWrite(i,HIGH);
  }

  //Printing numbers between 0 and 9 on LED
  for(int j = 0; j <= 9; j++)
  {
    for(int i = 2; i <= 8; i++)
    {
      digitalWrite(i,LOW);
    }
    delay(1000);

    if(j==0)
    {
      digitalWrite(pinG,HIGH);
      delay(dTime);
    }
    
    else if(j==1)
    {
      digitalWrite(pinA,HIGH);
      digitalWrite(pinD,HIGH);
      digitalWrite(pinE,HIGH);
      digitalWrite(pinF,HIGH);
      digitalWrite(pinG,HIGH);
      delay(dTime);
    }

    else if(j==2)
    {
      digitalWrite(pinC,HIGH);
      digitalWrite(pinF,HIGH);
      delay(dTime);
    }

    else if(j==3)
    {
      digitalWrite(pinE,HIGH);
      digitalWrite(pinF,HIGH);
      delay(dTime);
    }

    else if(j==4)
    {
      digitalWrite(pinA,HIGH);
      digitalWrite(pinD,HIGH);
      digitalWrite(pinE,HIGH);
      delay(dTime);
    }

    else if(j==5)
    {
      digitalWrite(pinB,HIGH);
      digitalWrite(pinE,HIGH);
      delay(dTime);
    }

    else if(j==6)
    {
      digitalWrite(pinB,HIGH);
      delay(dTime);
    }

    else if(j==7)
    {
      digitalWrite(pinD,HIGH);
      digitalWrite(pinE,HIGH);
      digitalWrite(pinF,HIGH);
      digitalWrite(pinG,HIGH);
      delay(dTime);
    }

    else if(j==8)
    {
      delay(dTime);
    }

    else if(j==9)
    {
      digitalWrite(pinE,HIGH);
      delay(dTime);
    }
  }
  
}
