// C++ code
//
#include <Servo.h>

Servo servo;
int servoPin = 9;
int inp = A0;
int x;

void setup()
{
  servo.attach(servoPin);
  pinMode(inp,INPUT);
  Serial.begin(9600);
}

void loop()
{
  x=analogRead(inp);
  int val = map(x,1023,618,0,180);
  servo.write(val);
  Serial.println(x);
}
