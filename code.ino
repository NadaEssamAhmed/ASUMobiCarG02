#include <AFMotor.h> //Adafruit Motor Shield Library. First you must download and install AFMotor library
#include <Servo.h> //add Servo Motor library
#include <NewPing.h> //add Ultrasonic sensor library
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
#define KP 2 //experiment to determine this, start by something small that just makes your bot follow the line at a slow speed
#define KD 5 //experiment to determine this, slowly increase the speeds and adjust this value. ( Note: Kp < Kd) 
#define M1_minumum_speed 150  //minimum speed of the Motor1
//#define M2_minumum_speed 150  //minimum speed of the Motor2
#define M1_maksimum_speed 250 //max. speed of the Motor1
//#define M2_maksimum_speed 250 //max. speed of the Motor2
#define MIDDLE_SENSOR 4       //number of middle sensor used
#define NUM_SENSORS 5         //number of sensors used
#define TIMEOUT 2500          //waits for 2500 us for sensor outputs to go low
#define EMITTER_PIN 2         //emitterPin is the Arduino digital pin that controls whether the IR LEDs are on or off. Emitter is controlled by digital pin 2
#define DEBUG 0
//sensors 0 through 5 are connected to analog inputs 0 through 5, respectively

unsigned int sensorValues[NUM_SENSORS];
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);
Servo myservo;
boolean goesForward=false;
int distance = 100;
int speedSet = 0;
void setup() {
Serial.begin(9600);
pinMode(A3,OUTPUT);
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
delay(100);

}

void loop() {
if(Serial.available()){
h=Serial.read();
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
digitalWrite(A3,HIGH);
}
void right_car()
{
motor1.run(FORWARD);
motor1.setSpeed(sp);
motor2.run(FORWARD);
motor2.setSpeed(sp);
motor3.run(BACKWARD);
motor3.setSpeed(sp);
motor4.run(BACKWARD);
motor4.setSpeed(sp);
}
void left_car()
{
motor1.run(BACKWARD);
motor1.setSpeed(sp);
motor2.run(BACKWARD);
motor2.setSpeed(sp);
motor3.run(FORWARD);
motor3.setSpeed(sp);
motor4.run(FORWARD);
motor4.setSpeed(sp);
}
void forward_right_car()
{
motor1.run(FORWARD);
motor1.setSpeed(sp);
motor2.run(FORWARD);
motor2.setSpeed(sp);
motor3.run(RELEASE);
motor4.run(RELEASE);
}
void forward_left_car()
{
motor1.run(RELEASE);
motor2.run(RELEASE);
motor3.run(FORWARD);
motor3.setSpeed(sp);
motor4.run(FORWARD);
motor4.setSpeed(sp);
}
void back_right_car()
{
motor1.run(BACKWARD);
motor1.setSpeed(sp);
motor2.run(BACKWARD);
motor2.setSpeed(sp);
motor3.run(RELEASE);
motor4.run(RELEASE);
}
void back_left_car()
{
motor1.run(RELEASE);
motor2.run(RELEASE);
motor3.run(BACKWARD);
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
analogWrite(A3,LOW);
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
motor2.run(FORWARD);
motor2.setSpeed(220);
motor3.run(BACKWARD);
motor3.setSpeed(220);
motor4.run(BACKWARD);
motor4.setSpeed(220);
delay(300);
moveForward();
}
void turnLeft() {
motor1.run(BACKWARD);
motor1.setSpeed(220);
motor2.run(BACKWARD);
motor2.setSpeed(220);
motor3.run(FORWARD);
motor3.setSpeed(220);
motor4.run(FORWARD);
motor4.setSpeed(220);
delay(300);
moveForward();
}
