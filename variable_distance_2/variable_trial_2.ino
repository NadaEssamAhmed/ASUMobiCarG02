#include <AFMotor.h> //Adafruit Motor Shield Library. First you must download and install AFMotor library

  AF_DCMotor motor1 (1, MOTOR12_1KHZ); //create motor #1 using M1 output on Motor Drive Shield, set to 1kHz PWM frequency
  AF_DCMotor motor2 (2, MOTOR12_1KHZ); //create motor #2 using M2 output on Motor Drive Shield, set to 1kHz PWM frequency
  AF_DCMotor motor3 (3, MOTOR12_1KHZ); //create motor #1 using M1 output on Motor Drive Shield, set to 1kHz PWM frequency
  AF_DCMotor motor4 (4, MOTOR12_1KHZ); //create motor #2 using M2 output on Motor Drive Shield, set to 1kHz PWM frequency
  char h;
  int sp=180;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
        if (Serial.available()>0)
{  float x=Serial.parseFloat();  //enter the degree
    Serial.println(x);
       float t=(x*1000)/sp;
       Serial.println(t);
        forward_car();
        delay(t);
        stop_car ();
        
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
  
void stop_car ()
{
motor1.run(RELEASE);
motor2.run(RELEASE);
motor3.run(RELEASE);
motor4.run(RELEASE);
//analogWrite(A3,LOW);
}
