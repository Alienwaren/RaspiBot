#include <Servo.h>
PROGMEM const int servoPin = 9;
Servo eyesOne;
String message = "";
void setup() {
  // put your setup code here, to run once:
 eyesOne.attach(servoPin);
 resetServo(1);
 Serial.begin(9600);
}

void loop() {
  
    
   message = getMessage();
   if(message.indexOf("left") >= 0)
   {
     setServoPos(1,180);
     message = "";
   }else if(message.indexOf("right") >= 0)
   {
     setServoPos(1,0);
     message = "";
   }else if(message.indexOf("center") >= 0)
  {
    setServoPos(1,90);
     message = "";
  }
   delay(100);
}
void resetServo(int servoNumber)
{
  if(servoNumber == 1)
  {
    if(eyesOne.read() != 90)
    {
      eyesOne.write(90);
    }
  }
}
void setServoPos(int servoNumber, int angle)
{
  Serial.println("setting servo position");
  if(servoNumber == 1)
  {
    if(eyesOne.read() != angle && (angle >= 0 && angle <= 180))
    {
      eyesOne.write(angle);
    }
  }
}
String getMessage()
{
  String bufferMessage = "";
  while(Serial.available() > 0)
  {
    int byteRecv = Serial.read();
    bufferMessage += (char)byteRecv;
    if(byteRecv == '\n')
    {
      Serial.println(bufferMessage);
      return bufferMessage;
    }
  }
  return "noMessage";
}
