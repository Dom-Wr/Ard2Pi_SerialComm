#include <Servo.h>
#include <Point.h>
#include <Navigator.h>
#include <Wire.h>
#include <Razor.h>
#include <Message_Struct.h>

Message_Struct message;

Point location (0,0);
double def_heading = 0.0;
double heading;

Razor razor;
Navigator navigator(location, razor );

//Servo rightservo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  razor.Razor_Init();
  heading = razor.getHeading();
  //navigator.setHeading(heading);
  //rightservo.attach(5);

  /*
  Serial.print("The initial heading is: ");
  Serial.print(heading);
  Serial.println();

  Serial.print("The setup is complete");
  */

}

void loop() {
  // put your main code here, to run repeatedly:
  
  //navigator.setHeading(heading);
  //rightservo.write(0);

  /*
  Serial.print("The heading is: ");
  Serial.print(heading);
  Serial.println();
  */

  if (Serial.available())
  {
    if (1 == (Serial.read()-'0')) //Pi is requesting heading
    {
      heading = razor.getHeading();
      message.EncodeMagn(heading);
      message.send();
    }

    else if (2 == (Serial.read()-'0')) //Pi is sending commands
    {
      message.receive();
    }
  }

}
