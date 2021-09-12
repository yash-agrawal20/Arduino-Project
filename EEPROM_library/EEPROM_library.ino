//Using EEPROM library
//Date: 22-08-2021
//Yash Agrawal

#include <EEPROM.h>

int ledPin = 13;
int buttonPin = 2;

int lastButtonState = 1;
int lastPress;
int debounceTime = 20;
int counter;

void setup() 
{
  pinMode(ledPin,OUTPUT);
  pinMode(buttonPin,INPUT_PULLUP);
  Serial.begin(9600);
  counter = EEPROM.read(0);
  EEPROM.write(0,0);
}

void loop()
{
  
  int buttonState = digitalRead(buttonPin);
  if(millis() - lastPress > debounceTime)
  {
    lastPress = millis();
    if(buttonState == 0 && lastButtonState == 1)
    {
      counter++;
      EEPROM.write(0,counter);
      digitalWrite(ledPin,HIGH);
      delay(1000);
      lastButtonState = 0;

      Serial.print("Counter =  ");
      Serial.println(counter);
    }

    if(buttonState == 1 && lastButtonState == 0)
    {
      lastButtonState = 1;
      digitalWrite(ledPin,LOW);
    }

  }

}
