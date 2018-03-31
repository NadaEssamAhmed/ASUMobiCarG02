int sensorPin   = A0;   //Select the input pin for the potentiometer
int outputPin   = 13;   //Select the pin for the output (LED)
int sensorValue = 0;    //To store the value coming from the sensorPin

void setup()
{
  //Declare the outputPin as an OUTPUT:
  pinMode(outputPin, OUTPUT);
}
void loop()
{
  //Read value of sensor
  sensorValue=analogRead(sensorPin);
  //Check if smaller than certain value
  if(sensorValue <= 30)
  {
    //Don't light the led
    digitalWrite(outputPin,LOW);
  }
  else
  {
    //Light the led
    digitalWrite(outputPin,HIGH);
  }
}
