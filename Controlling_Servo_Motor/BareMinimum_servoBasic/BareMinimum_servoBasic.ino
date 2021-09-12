//Controlling a Servo Motor using Arduino
//Date: 21-08-2021
//Yash Agrawal

#include<Servo.h>

const int Pin = 11;
float Pos = 0;
Servo my_Servo;

void setup() 
{
  Serial.begin(9600);
  my_Servo.attach(Pin);
}

void loop() 
{
  Serial.println("Enter the angle for the Servo Pin: ");
  while(Serial.available() == 0)
  {}

  Pos = Serial.parseInt();
  my_Servo.write(Pos);

}
