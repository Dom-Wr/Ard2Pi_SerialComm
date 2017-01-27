#include <Message_Struct.h>

Message_Struct message;
double heading = 1.234;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //Serial.println("The data transmission has started");
}

void loop() {
  // put your main code here, to run repeatedly:

  //send data only when you receive data
  if (Serial.available())
  {
    if (1 == (Serial.read()-'0')) //Pi is requesting heading
    {
      message.EncodeMagn(heading);
      message.send();
    }

    else if (2 == (Serial.read()-'0')) //Pi is sending commands
    {
      message.receive();
    }
  }

}
