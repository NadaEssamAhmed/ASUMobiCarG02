// change condition of if statement
#include <AFMotor.h>
AF_DCMotor motor1 (1, MOTOR12_1KHZ);
AF_DCMotor motor2 (2, MOTOR12_1KHZ);
AF_DCMotor motor3 (3, MOTOR12_1KHZ);
AF_DCMotor motor4 (4, MOTOR12_1KHZ);
int left=A3;
int center=A4;
int right=A5;
int Left=0;
int Center=0;
int Right=0;
void setup() {
pinMode(left,INPUT);
pinMode(center,INPUT);
pinMode(right,INPUT);
}
void loop() {
Left=digitalRead(left);
Center=digitalRead(center);
Right=digitalRead(right);
if((Left==1 && Center==1 && Right==1) || (Left==0 &&
Center==1 && Right==0) || (Left==1 && Center==0 &&
Right==1) )
forward_car();
else if(Left==1 && Center==1 && Right==0)
right_car();
else if (Left==1 && Center==1 && Right==0)
forward_right_car();
else if(Left==0 && Center==1 && Right==1)
left_car();
else if(Left==0 && Center==0 && Right==1)
forward_left_car();
}
void forward_car()
{
motor1.run(FORWARD);
motor2.run(FORWARD);
motor3.run(FORWARD);
motor4.run(FORWARD);
}
void right_car()
{
motor1.run(FORWARD);
motor2.run(BACKWARD);
motor3.run(BACKWARD);
motor4.run(FORWARD);
}
void left_car()
void left_car()
{
motor1.run(BACKWARD);
motor2.run(FORWARD);
motor3.run(FORWARD);
motor4.run(BACKWARD);
}
void forward_right_car()
{
motor1.run(FORWARD);
motor2.run(RELEASE);
motor3.run(RELEASE);
motor4.run(FORWARD);
}
void forward_left_car()
{
motor1.run(RELEASE);
motor2.run(FORWARD);
motor3.run(FORWARD);
motor4.run(RELEASE);
}
Last modified: 00:59
