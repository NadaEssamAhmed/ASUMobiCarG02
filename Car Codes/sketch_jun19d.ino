#include <AFMotor.h> //Adafruit Motor Shield Library. First you must download and install AFMotor library
  AF_DCMotor motor1 (1, MOTOR12_1KHZ); //create motor #1 using M1 output on Motor Drive Shield, set to 1kHz PWM frequency
  AF_DCMotor motor2 (2, MOTOR12_1KHZ); //create motor #2 using M2 output on Motor Drive Shield, set to 1kHz PWM frequency
  AF_DCMotor motor3 (3, MOTOR12_1KHZ); //create motor #1 using M1 output on Motor Drive Shield, set to 1kHz PWM frequency
  AF_DCMotor motor4 (4, MOTOR12_1KHZ); //create motor #2 using M2 output on Motor Drive Shield, set to 1kHz PWM frequency
float period ; //the value is  a number of milliseconds
char h;
int sp=180;
 float v=(32.5*2*PI*sp)/(60*1000);
float d;
void setup() {
 
}

void loop(){
  if(Serial.available()){
  h=Serial.read();
  Serial.println(h);
  if (h=='z'){
    while(1){
  if (Serial.available()>0){
    d=Serial.parseFloat();
period=d*1000/v;
for(int i=0;i<period;i++){
  forward_car();
  delay(1000);
  
}
delay(1000);
stop_car ();
  }
}}}}
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

