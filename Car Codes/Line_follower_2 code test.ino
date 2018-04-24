// change condition of if statement
#include <AFMotor.h>
AF_DCMotor motor1 (1, MOTOR12_1KHZ);
AF_DCMotor motor2 (2, MOTOR12_1KHZ);
AF_DCMotor motor3 (3, MOTOR12_1KHZ);
AF_DCMotor motor4 (4, MOTOR12_1KHZ);
int sp=180;
int left=17;
int center=18;
int right=19;
int Left;
int Center;
int Right;
void setup() {
pinMode(left,INPUT);
pinMode(center,INPUT);
pinMode(right,INPUT);
delay(100);
}
void loop() {
 while(1){
Left=digitalRead(left);
Center=digitalRead(center);
Right=digitalRead(right);
if((Left==0 && Center==0 && Right==0)||(Left==1 && Center==0 &&Right==1))
{
  forward_car();
  Serial.println("forward");
  
}
else if(Left==0 && Center==0 && Right==1)
{
  right_car();
    Serial.println("right");

  if(Left=0 &&Center==1 &&Right==0){
  right_car();
    Serial.println("right");

  }
    
}
else if (Left==0 && Center==1 && Right==1)
{
  right_car();
      Serial.println("right");

  if(Left=0 &&Center==1 &&Right==0){
  right_car();
      Serial.println("right");

  }
  
}
else if(Left==1 && Center==0 && Right==0){

  left_car();
      Serial.println("left");

  if(Left=0 &&Center==1 &&Right==0){
  left_car();
      Serial.println("left");

  }
}
else if(Left==1 && Center==1 && Right==0)
{
  left_car();
      Serial.println("left");

 if(Left=0 &&Center==1 &&Right==0){
  left_car();
      Serial.println("left");

  }
}
}
}
 void forward_car()
  {
  motor1.run(FORWARD);
  motor1.setSpeed(sp);
  motor2.run(FORWARD);
  motor2.setSpeed(sp);
  motor3.run(FORWARD);
  motor3.setSpeed(sp);
  motor4.run(FORWARD);
  motor4.setSpeed(sp);
  }
 
  void right_car()
  {
  motor1.run(BACKWARD);
  motor1.setSpeed(sp);
  motor2.run(FORWARD);
  motor2.setSpeed(sp);
  motor3.run(BACKWARD);
  motor3.setSpeed(sp);
  motor4.run(FORWARD);
  motor4.setSpeed(sp);
  }
  
  void left_car()
  {
  motor1.run(FORWARD);
  motor1.setSpeed(sp);
  motor2.run(BACKWARD);
  motor2.setSpeed(sp);
  motor3.run(FORWARD);
  motor3.setSpeed(sp);
  motor4.run(BACKWARD);
  motor4.setSpeed(sp);
  }
