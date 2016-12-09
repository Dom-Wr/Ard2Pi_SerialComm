#include <Message_Struct.h>


Message_Struct message;
double heading = 1.234;


void setup(){
  Serial.begin(9600);
}

void loop(){
  message.EncodeMagn(heading);
  message.send();

  delay(20);
}
