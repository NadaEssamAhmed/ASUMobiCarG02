 #include <AFMotor.h> //Adafruit Motor Shield Library. First you must download and install AFMotor library
 #include <RedBot.h> //add Line Follower sensor library
  AF_DCMotor motor1 (1, MOTOR12_1KHZ); //create motor #1 using M1 output on Motor Drive Shield, set to 1kHz PWM frequency
  AF_DCMotor motor2 (2, MOTOR12_1KHZ); //create motor #2 using M2 output on Motor Drive Shield, set to 1kHz PWM frequency
  AF_DCMotor motor3 (3, MOTOR12_1KHZ); //create motor #1 using M1 output on Motor Drive Shield, set to 1kHz PWM frequency
  AF_DCMotor motor4 (4, MOTOR12_1KHZ); //create motor #2 using M2 output on Motor Drive Shield, set to 1kHz PWM frequency
  char h;
  int sp=60;
  int S1,S2,S3;
void setup() {
  // put your setup code here, to run once:
  
pinMode(S1, INPUT);
pinMode(S2, INPUT);
pinMode(S3,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
S1 = digitalRead(2);
S2 = digitalRead(4);
S3 = digitalRead(3);

if(!S3 && !S2 && !S1) //move forward
{
//Serial. println( "forward" ) ;

forward_car();
        if(!S3 && S2 && !S1) //Stop
{
 // Serial. println( "forward" ) ;

forward_car();
  }

}
if(!S3 && !S2 && S1) //move right
{
  //Serial. println( "low right" ) ;
  left_car();
        if(!S3 && S2 && !S1) //Stop
{
  //Serial. println( "low right" ) ;
  left_car();
  }
}

if(!S3 && S2 && S1) //move right
{
  //Serial. println( "right" ) ;
  left_car();
      if(!S3 && S2 && !S1) //Stop
{
 // Serial. println( "right" ) ;
  left_car();
  
  }
}

if(S3 && !S2 && S1) //move left
{
  
  //Serial. println( "low left" ) ;
  right_car();
    if(!S3 && S2 && !S1) //Stop
{
  //Serial. println( "low left" ) ;
  right_car();
  }
}

if(S3 && S2 && !S1) //move left
{
  //Serial. println( "left" ) ;
  right_car();
  if(!S3 && S2 && !S1) //Stop
{
  //Serial. println( "left" ) ;
  right_car();
  
  }
}

if(S3 && !S2 && S1) //Stop
{
  //Serial. println( "forward" ) ;
forward_car();
if(!S3 && S2 && !S1) //Stop

{
  //Serial. println( "forward" ) ;
forward_car();
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
  void back_car()
  {
  motor1.run(BACKWARD);
  motor1.setSpeed(sp);
  motor2.run(BACKWARD);
  motor2.setSpeed(sp);
  motor3.run(BACKWARD);
  motor3.setSpeed(sp);
  motor4.run(BACKWARD);
  motor4.setSpeed(sp);
 // digitalWrite(A3,HIGH);
  }
  void right_car()
  {
  motor1.run(FORWARD);
  motor1.setSpeed(sp);
  motor2.run(BACKWARD);
  motor2.setSpeed(sp);
  motor3.run(BACKWARD);
  motor3.setSpeed(sp);
  motor4.run(FORWARD);
  motor4.setSpeed(sp);
  }
  void left_car()
  {
  motor1.run(BACKWARD);
  motor1.setSpeed(sp);
  motor2.run(FORWARD);
  motor2.setSpeed(sp);
  motor3.run(FORWARD);
  motor3.setSpeed(sp);
  motor4.run(BACKWARD);
  motor4.setSpeed(sp);
  }
 
void stop_car ()
{
motor1.run(RELEASE);
motor2.run(RELEASE);
motor3.run(RELEASE);
motor4.run(RELEASE);
//analogWrite(A3,LOW);
}

