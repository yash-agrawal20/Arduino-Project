// Whack a mole game
// 25-08-2021
// Yash Agrawal

// Variables for joustick
int sX = A0;     //joystick x axis, analog input
int sY = A1;     //joystick y axis, analog input
int sSX;         //reading from sX
int sSY;         //reading from sY
int sS;

// Game variables
int rNum;                        //random int choosing the random light to turn on
const int dTime=1000;
int ledPins[7]={2,3,4,5,6,7,8};  //initializing led's
int pinCount=7;                  //number of led pins

void setup() 
{
  Serial.begin(9600);
  pinMode(sX, INPUT);
  pinMode(sY, INPUT);

  for (int Pin = 0;Pin < pinCount;Pin++) 
  { 
    pinMode(ledPins[Pin], OUTPUT);
  }
}

void loop() 
{
  rNum=random(2,9); //generating random choice
  delay(dTime);
  digitalWrite(ledPins[rNum], HIGH); //lighting the randomly chosen bulb
  delay(dTime); 

  sSX = analogRead(sX); //reading x axis input
  delay(dTime);
  sSY = analogRead(sY); //reading y axis input

  //converting y and x inputs to 4 possibilities.
  //0 and 1023 are the maximum values on each axis of the joystick, as measured.
  sS=0;
  switch (sSX) 
  {
    case 0:
    sS=1;      // Left
    break;
    case 1023:
    sS=2;      // Right
    break;
  }
  
  switch (sSY) 
  {
    case 0:
    sS=3;      // Up
    break;
    case 1023:
    sS=4;      // Down
    break;
  }
  
  //turning off the randomly selected bulb, after the joystick choice was made
  digitalWrite(ledPins[rNum], LOW); 
  //checking if the user input the correct direction of the lit bulb
  if (sS-1==rNum)
  {
    //blinking LED 5 indicating correct choice
    for (int k=0; k<=3; k++) 
    {     
      digitalWrite(ledPins[4], HIGH);
      delay(dTime);
      digitalWrite(ledPins[4], LOW);
      delay(dTime);
    }
  }
  
  else
  {
    //blinking LED 6 indicating incorrect choice
    for (int i=0; i<=3; i++) 
    {       
      digitalWrite(ledPins[5], HIGH);
      delay(dTime);
      digitalWrite(ledPins[5], LOW);
      delay(dTime);
    }
  }  
}
