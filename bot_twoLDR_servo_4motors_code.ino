// C++ code
//
#include <Servo.h>
Servo servo;
int x,y,dir;
int val=90;
int speedf,speed;
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  servo.attach(3);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);
  pinMode(10,OUTPUT);
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(A1,OUTPUT);
}

void loop()
{
  x=analogRead(A0);
  y=analogRead(A1);
  dir=x-y;
  speedf=x+y;
  if(dir>880&&dir<1000){
    val = map(dir,880,1000,90,180);
  }
  if(dir<865&&dir>500){
    val = map(dir,865,500,90,0);
  }
  servo.write(val);
  speed=map(speedf,1181,500,10,255);
  Serial.println(speed);
  digitalWrite(6,HIGH);
  digitalWrite(5,LOW);
  //analogWrite(9,150);
  analogWrite(9,speed);
  digitalWrite(0,HIGH);
  digitalWrite(1,LOW);
  analogWrite(10,speed);
  //analogWrite(10,150);
  //for(int i=0;i<180;i=i+20){
    //servo.write(i);
    //delay(1000);
  //}
}