#include <Message_Struct.h>

Message_Struct message;

unsigned char byte_rcv[256];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  /*
  for(int i = 0; i < 256; i++)
  {
    byte_rcv[i] = 0x00;
  }
  */
}

void loop() {

  int bytes = 0;
  bytes = Serial.available();
  if (bytes)
  {

    for(int i = 0; i < bytes; i++)
    {
      byte_rcv[i] = Serial.read();
    }
    Serial.write(byte_rcv, bytes);
  }

  delay(2000);

}
