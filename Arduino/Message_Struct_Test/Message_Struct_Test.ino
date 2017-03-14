#include <Message_Struct.h>


Message_Struct message;
double heading = 1.234;


void setup(){
  Serial.begin(9600);
  //pinMode(OUTPUT, 13);
}

void loop(){
  message.setHeading(heading);
  //message.num_bytes = Serial.available();
  message.RunComm();
}
