#include <Message_Struct.h>

Message_Struct message;
unsigned char bytesarray[4] = {182,243,157,63};
unsigned char byte_rcv[4];
int startPosition = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //Serial.println("The data transmission has started");
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.write(bytesarray,4);
  if (Serial.available() > 0)
  {
    int bytes = Serial.available();
    for(int i = startPosition; i < startPosition+bytes; i++)
    {
      byte_rcv[i] = Serial.read();
    }
    Serial.print("Serial is available");
    Serial.readBytes(byte_rcv,Serial.available());
  }

  for (int i=0; i<4; i++)
  {
    Serial.println();
    Serial.print("The byte in position ");
    Serial.print(i+1);
    Serial.print(" is:");
    Serial.print(byte_rcv[i]);
    Serial.println();
  }

  delay(1000);


}
