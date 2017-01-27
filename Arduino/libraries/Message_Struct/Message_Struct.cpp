#include "Message_Struct.h"
#include "string.h"

void float_to_bytes (byte *bytes_arr, float floatval);
float bytes_to_float (byte* bytes_arr);

Message_Struct::Message_Struct ()
{}

void Message_Struct::EncodeMagn(double heading)
{
    //typecast double to float
    float heading_float = (float) heading;
    //byte bytes[4];

    float_to_bytes(&bytes_send[0], heading_float);

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

  Serial.write(bytes_send, 4);

}

void Message_Struct::receive()
{
  //Insert Arduino logic for reading byte data from serial port
  //Read byte format
  //bytes_receive = Serial.read();
  byte byte_rcv_fmt[4];
  Serial.readBytes(byte_rcv_fmt, 4);
  Serial.readBytes(bytes_receive, 4);
  float fval = bytes_to_float(bytes_receive);

  /*
  cout << "The float val is: " << fval << endl;
  */
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

float bytes_to_float (byte* bytes_arr)
{
  union
  {
    float a;
    unsigned char bytes [4];
  } u;

  //u.bytes = bytes_arr;
  memcpy(u.bytes, bytes_arr, 4);

  return u.a;
}

void int_to_bytes (byte* bytes_arr, int intval)
{
  union
  {
    int a;
    unsigned char in_bytes[4];
  } u;

  u.a = intval;
  memcpy (bytes_arr, u.in_bytes, 4);
}

int bytes_to_int(byte* bytes_arr)
{
  union
  {
    int a;
    unsigned char bytes [4];
  } u;

  memcpy(u.bytes, bytes_arr, 4);
}




/*
unsigned char bytes_to_char_arr (byte* bytes_arr)
{
  union
  {
    unsigned char inc_bytes [];
    unsigned char bytes [];
  } u;

  u.inc_bytes = bytes_arr;

  return  u.bytes;
}
*/
