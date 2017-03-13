#include <Message_Struct.h>

Message_Struct message;

unsigned char byte_rcv[256];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);

  
  for(int i = 0; i < 256; i++)
  {
    byte_rcv[i] = 0x00;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
    //if (1 == (Serial.read()-'0'))
    //{
      //Test if Arduino is correctly prompted send date to RasPi
      //Test verified and completed

      //Add while loop here
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

     
    //}  

  delay(2000);

}
