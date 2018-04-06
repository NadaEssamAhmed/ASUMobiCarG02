  #include <AFMotor.h> //Adafruit Motor Shield Library. First you must download and install AFMotor library
  #include <Servo.h> //add Servo Motor library
  #include <NewPing.h> //add Ultrasonic sensor library
  #include <RedBot.h> //add Line Follower sensor library
  AF_DCMotor motor1 (1, MOTOR12_1KHZ); //create motor #1 using M1 output on Motor Drive Shield, set to 1kHz PWM frequency
  AF_DCMotor motor2 (2, MOTOR12_1KHZ); //create motor #2 using M2 output on Motor Drive Shield, set to 1kHz PWM frequency
  AF_DCMotor motor3 (3, MOTOR12_1KHZ); //create motor #1 using M1 output on Motor Drive Shield, set to 1kHz PWM frequency
  AF_DCMotor motor4 (4, MOTOR12_1KHZ); //create motor #2 using M2 output on Motor Drive Shield, set to 1kHz PWM frequency
  char h;
  int sp=100;
  #define TRIG_PIN A0 // Ultra
  #define ECHO_PIN A1
  #define MAX_DISTANCE 200
//line follower
  RedBotSensor left_sen = RedBotSensor(A3);   
  RedBotSensor center_sen = RedBotSensor(A4); 
  RedBotSensor right_sen = RedBotSensor(A5);  
  int lineStandard = 1000;
//UltraSonic
  NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);
  Servo myservo;
  boolean goesForward=false;
  int distance = 100;
  int speedSet = 0;
  
//Void setup
  
  void setup() {
  Serial.begin(9600);
  //pinMode(A3,OUTPUT);
  myservo.attach(9);
  myservo.write(115);
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
//  LineFollwer 
  Serial.println("IR Sensor Readings:: ");
  delay(100);
  
  }
  
  void loop() {
  if(Serial.available()){
  h=Serial.read();
  Serial.println(h);
  if(h=='C') {
  while(1){
  if(Serial.available()){
  h=Serial.read();
  if(h=='f')sp=150;
  if(h=='s')sp=200;
  if(h=='t')sp=255;
  if(h=='F')forward_car();
  if(h=='B')back_car();
  if(h=='R')right_car();
  if(h=='L')left_car();
  if(h=='K')forward_right_car();
  if(h=='P')forward_left_car();
  if(h=='M')back_right_car();
  if(h=='N')back_left_car();
  if(h=='S')stop_car ();
  }
  if(h=='c'){stop_car ();break;}
  }
  }
  if(h=='V') {
  while(1){
  //Begining
  int distanceR = 0;
  int distanceL = 0;
  delay(40);
  if(distance<=35)
  {
  moveStop();
  delay(100);
  moveBackward();
  delay(300);
  moveStop();
  delay(200);
  distanceR = lookRight();
  delay(200);
  distanceL = lookLeft();
  delay(200);
  if(distanceR>=distanceL)
  {
  turnRight();
  moveStop();
  }
  else
  {
  turnLeft();
  moveStop();
  }
  }
  else moveForward();
  distance = readPing();
  if(Serial.available()){
  h=Serial.read();
  }
  if(h=='v'){stop_car ();break;}
  }
  }
  if(h=='U'){
    while(1){
  Serial.print(left_sen.read());
  Serial.print("\t");  
  Serial.print(center_sen.read());
  Serial.print("\t"); 
  Serial.print(right_sen.read());
  Serial.println();

  // if on the line drive left and right at the same speed (left is CCW / right is CW)
  if(center_sen.read() > lineStandard)
  {//right
   right_car();
  }
  //data_sheet
  // if the line is under the right sensor, adjust relative speeds to turn to the right
  else if(right_sen.read() > lineStandard)
  {//left
  left_car();
  }
  //data_sheet
  // if the line is under the left sensor, adjust relative speeds to turn to the left
  else if(left_sen.read() > lineStandard)
  {//right
  right_car();
  }
  //data_sheet
  // if all sensors are on black or up in the air, stop the motors.
  // otherwise, run motors given the control speeds above.
  if((left_sen.read() > lineStandard) && (center_sen.read() > lineStandard) && (right_sen.read() > lineStandard) )
  {
    //stop
    stop_car ();
  }
  else
  {
  //any dir
    forward_car();
  }
  delay(0);  // add a delay to decrease sensitivity.
    if(Serial.available()){
  h=Serial.read();
  }
  if(h=='u'){stop_car ();break;}
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
  void back_right_car()
  {
  motor1.run(BACKWARD);
  motor1.setSpeed(sp);
motor2.run(RELEASE);
motor2.setSpeed(sp);
motor3.run(RELEASE);
motor4.run(BACKWARD);
}
void back_left_car()
{
motor1.run(RELEASE);
motor2.run(BACKWARD);
motor3.run(BACKWARD);
motor3.setSpeed(sp);
motor4.run(RELEASE);
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
int lookRight()
{
myservo.write(50);
delay(500);
int distance = readPing();
delay(100);
myservo.write(115);
return distance;
}
int lookLeft()
{
myservo.write(170);
delay(500);
int distance = readPing();
delay(100);
myservo.write(115);
return distance;
delay(100);
}
int readPing() {
delay(70);
int cm = sonar.ping_cm();
if(cm==0)
{
cm = 250;
}
return cm;
}
void moveStop() {
motor1.run(RELEASE);
motor2.run(RELEASE);
motor3.run(RELEASE);
motor4.run(RELEASE);
}
void moveForward() {
motor1.run(FORWARD);
motor1.setSpeed(180);
motor2.run(FORWARD);
motor2.setSpeed(180);
motor3.run(FORWARD);
motor3.setSpeed(180);
motor4.run(FORWARD);
motor4.setSpeed(180);
}
void moveBackward() {
motor1.run(BACKWARD);
motor1.setSpeed(180);
motor2.run(BACKWARD);
motor2.setSpeed(180);
motor3.run(BACKWARD);
motor3.setSpeed(180);
motor4.run(BACKWARD);
motor4.setSpeed(180);
}
void turnRight() {
motor1.run(FORWARD);
motor1.setSpeed(220);
motor2.run(BACKWARD);
motor2.setSpeed(220);
motor3.run(BACKWARD);
motor3.setSpeed(220);
motor4.run(FORWARD);
motor4.setSpeed(220);
delay(300);
moveForward();
}
void turnLeft() {
motor1.run(BACKWARD);
motor1.setSpeed(220);
motor2.run(FORWARD);
motor2.setSpeed(220);
motor3.run(FORWARD);
motor3.setSpeed(220);
motor4.run(BACKWARD);
motor4.setSpeed(220);
delay(300);
moveForward();
}

