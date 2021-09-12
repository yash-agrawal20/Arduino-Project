//Controlling the brightness of the LED using PWMs
//Date: 21-08-2021
//Yash Agrawal

const int redPin = 11;
const int bluePin = 10;
const int greenPin = 9;
const int dtime = 1000;

void setup() 
{
  pinMode(redPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(A2,INPUT);
}

void loop() 
{
  //any integer number between 0 and 255
  //it takes values between 0V and 5V  
 
  float b_potentiometer = analogRead(A2);
  float b_led = b_potentiometer / 4;
  analogWrite(redPin,b_led);
  analogWrite(bluePin,b_led);
  analogWrite(greenPin,b_led);
}
