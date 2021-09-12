//Measuring the distance between object using distnace sensors
//Date: 22-08-2021
//Yash Agrawal

const int trigPin=12;
const int echoPin=11;
int pingTime;

void setup() 
{
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(9600);
}

void loop() 
{
  digitalWrite(trigPin,LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  //Finds out how long the pulse stays high
  pingTime = pulseIn(echoPin,HIGH); 
  delay(25);
  Serial.println(pingTime);
  delay(1000);
}
