  #include <AFMotor.h> //Adafruit Motor Shield Library. First you must download and install AFMotor library
  #include <Servo.h> //add Servo Motor library
  #include <NewPing.h> //add Ultrasonic sensor library
  
  AF_DCMotor motor1 (1, MOTOR12_1KHZ); //create motor #1 using M1 output on Motor Drive Shield, set to 1kHz PWM frequency
  AF_DCMotor motor2 (2, MOTOR12_1KHZ); //create motor #2 using M2 output on Motor Drive Shield, set to 1kHz PWM frequency
  AF_DCMotor motor3 (3, MOTOR12_1KHZ); //create motor #1 using M1 output on Motor Drive Shield, set to 1kHz PWM frequency
  AF_DCMotor motor4 (4, MOTOR12_1KHZ); //create motor #2 using M2 output on Motor Drive Shield, set to 1kHz PWM frequency
  char h;
  int sp=80;
//speed of motors betwen 0 and 255, if you like you can change it
int pwm_speedA = 150;
int pwm_speedB = 145;
char command; 

void setup() {
Serial.begin(9600);
  
pinMode(2, INPUT);
pinMode(4, INPUT);
pinMode(7, INPUT);

}

void loop() {
  
if(digitalRead(2) == LOW && digitalRead(4) == LOW && digitalRead(7) == LOW){
  forward_car();
}
else if(digitalRead(2) == HIGH && digitalRead(4) == HIGH && digitalRead(7) == LOW){
forward_left_car();
delay(100);
}
else if(digitalRead(2) == HIGH && digitalRead(4) == LOW && digitalRead(7) == LOW){
left_car();
delay(100);
}
else if(digitalRead(2) == LOW && digitalRead(4) == LOW && digitalRead(7) == HIGH){
forward_right_car();
delay(100);
}
else if(digitalRead(2) == LOW && digitalRead(4) == HIGH && digitalRead(7) == HIGH){
right_car();
delay(100);
}
else if((digitalRead(7)==LOW &&digitalRead(4)==HIGH &&digitalRead (2)==LOW)||(digitalRead(7)==HIGH &&digitalRead(4)==LOW &&digitalRead (2)==HIGH)||(digitalRead(7)==HIGH &&digitalRead(4)==HIGH &&digitalRead (2)==HIGH))
  moveStop();
}

// function for driving straight
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
  void forward_right_car()
  {
  motor1.run(FORWARD);
  motor1.setSpeed(sp);
  motor2.run(RELEASE);
  motor2.setSpeed(sp);
  motor3.run(RELEASE);
  motor4.run(FORWARD);
  }
  void forward_left_car()
  {
  motor1.run(RELEASE);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor3.setSpeed(sp);
  motor4.run(RELEASE);
  motor4.setSpeed(sp);
  }
  void moveStop() {
motor1.run(RELEASE);
motor2.run(RELEASE);
motor3.run(RELEASE);
motor4.run(RELEASE);
}
