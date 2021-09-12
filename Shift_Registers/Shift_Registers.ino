//Using shift resistors to control LEDS
//Date: 22-08-2021
//Yash Agrawal

#define NUM_LEDS 8

const int latchPin = 10;
const int clockPin = 11;
const int dataPin = 8;
int delayTime = 1000;
int dataArray[8] = {0B00000001,0B00000010,0B00000100,0B00001000,0B00010000,0B00100000,0B01000000,0B10000000};
int randomNumber;

void setup()
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
}


void loop()
{
  //Loops through the LEDs in one direction
  for (int i = 0; i < NUM_LEDS; i++)
  {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, dataArray[i]);
    digitalWrite(latchPin, HIGH);
     delay(delayTime);   
  }
  
  //Loops through the LEDs in opposite direction
  for (int i = NUM_LEDS-1; i >= 0; i--)
  {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, dataArray[i]);
    digitalWrite(latchPin, HIGH);
    delay(delayTime);   
  }
  
  //Switcihng on random LEDs
  for (int i = 0; i <= (NUM_LEDS-1); i++)
  {
    randomNumber = random(NUM_LEDS-1);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, randomNumber);
    digitalWrite(latchPin, HIGH);
    delay(delayTime);   
  }

}
