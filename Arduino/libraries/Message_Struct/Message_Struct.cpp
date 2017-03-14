#include "Message_Struct.h"
#include "string.h"

void float_to_bytes (byte *bytes_arr, float floatval);
float bytes_to_float (byte* bytes_arr, int bytes_size);

Message_Struct::Message_Struct ()
{}

void Message_Struct::RunComm()
{
  //num_bytes = Serial.available();
  //if (num_bytes)
  //{
    receive();
    //Decode();
    //EncodeMagn();
    //send();
  //}

  //Implement Conditions Checking for num_bytes here
}

void Message_Struct::setHeading(double _heading)
{
  heading = _heading;
}

void Message_Struct::setDistance(double _distance)
{
  distance = _distance;
}


void Message_Struct::EncodeMagn()
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
  //This function is to be called Arduino loop function
  //It writes the received bytes to Message_Struct receive buffer
  unsigned char byte_rcv[256];
  //rcv_bytes_size = 0;
  int num_bytes = Serial.available();

  if (num_bytes)
  {
    for(int i = 0; i < num_bytes; i++)
    {
      byte_rcv[i] = Serial.read();
    }
    Serial.write(byte_rcv, num_bytes);
  }

  //memcpy(byte_rcv, bytes_receive, rcv_bytes_size);

  delay(2000);

  //Tested and Working
}

double Message_Struct::Decode()
{
  bytes_to_float(&bytes_receive[0], rcv_bytes_size);
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

float bytes_to_float (byte* bytes_arr, int bytes_size)
{
  union
  {
    float a;
    unsigned char bytes [256];
  } u;

  //u.bytes = bytes_arr;
  memcpy(u.bytes, bytes_arr, bytes_size);

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
