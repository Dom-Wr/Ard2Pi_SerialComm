#include <Message_Struct.h>

Message_Struct message;
//unsigned char bytesarray[4] = {182,243,157,63};
unsigned char byte_rcv[4];
int startPosition = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  //Serial.println("The data transmission has started");
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.write(bytesarray,4);
  if (Serial.available() > 0)
  {

    //Check to see if Serial availability is processed by the Arduino
    /*
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    delay(1000);
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    delay(1000);
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    delay(1000);
    */
    //Test verified and completed

 /*
    if (1 == (Serial.read()-'0'))
    { 
      //Test if Arduino is correctly prompted send date to RasPi
      
      digitalWrite(13, HIGH);
      delay(1000);
      digitalWrite(13, LOW);
      delay(1000);
      digitalWrite(13, HIGH);
      delay(1000);
      digitalWrite(13, LOW);
      delay(1000);
      digitalWrite(13, HIGH);
      delay(1000);
      digitalWrite(13, LOW);
      delay(1000);
      
      //Test verified and completed
        
      //Serial.print("Serial is available");
      //Serial.readBytes(byte_rcv,Serial.available());
      Serial.write(byte_rcv, 4);
    }
*/


    if (2 == (Serial.read() - '0'))
    {
      //Is Raspberry Pi prompting Arduino to read commands appropriately 
      
      digitalWrite(13, HIGH);
      delay(1000);
      digitalWrite(13, LOW);
      delay(1000);
      digitalWrite(13, HIGH);
      delay(1000);
      digitalWrite(13, LOW);
      delay(1000);
      digitalWrite(13, HIGH);
      delay(1000);
      digitalWrite(13, LOW);
      delay(1000);
      
      //Test currently passes 

      /*
      int bytes = Serial.available();
      for(int i = startPosition; i < startPosition+bytes; i++)
      {
        byte_rcv[i] = Serial.read();
      }
      */
      //The above section is responsible for the failure of the Arduino read btyes
      //Prompts and threads on Linx side have all been checked to be working correctly
      //The prompts are being correctly received by the Arduino
      
    }

 
  
  }

  /*
  if(bytesarray == byte_rcv)
  {
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    delay(1000);
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    delay(1000);
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    delay(1000);
  }
  */

  /*
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
  */


}
