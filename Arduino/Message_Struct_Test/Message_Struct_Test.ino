#include <Message_Struct.h>


Message_Struct message;
double heading = 1.234;
double distance = 14.3;


void setup(){
  Serial.begin(9600);
  //pinMode(OUTPUT, 13);
}

void loop(){
  message.setHeading(heading);
  message.setDistance(distance);
  message.RunComm();
}
