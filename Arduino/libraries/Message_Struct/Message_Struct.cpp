#include "Message_Struct.h"
#include "string.h"

void float_to_bytes (byte *bytes_arr, float floatval);

Message_Struct::Message_Struct ()
{}

void Message_Struct::EncodeMagn(double heading)
{
    //typecast double to float
    float heading_float = (float) heading;
    //byte bytes[4];

    float_to_bytes(&bytes[0], heading_float);

    //Output statements for debugging EncodeMagn() function
    /*
    for (int i=0; i<4; i++)
    {
      Serial.println();
      Serial.print("The byte in position ");
      Serial.print(i+1);
      Serial.print(" is:");
      Serial.print(bytes[i]);
      Serial.println();
    }
    */
}

void Message_Struct::send()
{
  /*
  for (int i=0; i<4; i++)
  {
    Serial.write(bytes[i]);
  }
  */

  Serial.write(bytes, 4);


  //Serial.println();
}

double Message_Struct::DecodeMagn()
{

}

void float_to_bytes (byte* bytes_arr, float floatval)
{
  union
  {
    float a;
    unsigned char bytes [4];
  } u;

  u.a = floatval;
  memcpy (bytes_arr, u.bytes, 4);
}
