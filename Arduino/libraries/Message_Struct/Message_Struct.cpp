#include "Message_Struct.h"
#include "string.h"

void float_to_bytes (byte *bytes_arr, float floatval);
float bytes_to_float (byte* bytes_arr, int bytes_size);

Message_Struct::Message_Struct ()
{}

void Message_Struct::RunComm()
{
    receive();
    Decode();
    Encode();
    send();
}

void Message_Struct::setHeading(double _heading)
{
  heading = _heading;
}

void Message_Struct::setDistance(double _distance)
{
  distance = _distance;
}


void Message_Struct::Encode()
{
    //typecast double to float
    float heading_float = (float) heading;
    float distance_float = (float) distance;
    //byte bytes[4];

    float_to_bytes(&bytes_send[0], heading_float);
    float_to_bytes(&bytes_send[4], distance_float);

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
  Serial.write(bytes_send, snd_bytes_size);
}

void Message_Struct::receive()
{
  //Insert Arduino logic for reading byte data from serial port
  //Read byte format
  //This function is to be called Arduino loop function
  //It writes the received bytes to Message_Struct receive buffer
  unsigned char byte_rcv[256];
  int num_bytes = Serial.available();

  //Insert conditions checking for num_bytes
  //So that the num_bytes will only be 8

  rcv_bytes_size = num_bytes;
  if (num_bytes)
  {
    for(int i = 0; i < num_bytes; i++)
    {
      byte_rcv[i] = Serial.read();
    }
    //Serial.write(byte_rcv, num_bytes);
  }

  memcpy(bytes_receive, byte_rcv, rcv_bytes_size);
  //Serial.write(bytes_receive, rcv_bytes_size);

  //Move this functionality out to main function
  delay(2000);

  //Tested and Working
}

double Message_Struct::Decode()
{
  float val1 = bytes_to_float(&bytes_receive[0], rcv_bytes_size/2);
  float val2 = bytes_to_float(&bytes_receive[4], rcv_bytes_size/2);

  des_heading = val1;
  des_distance = val2;

  //Testing Decode function
  /*
  unsigned char bytes_dec_test[256];
  float_to_bytes(&bytes_dec_test[0], des_heading);
  float_to_bytes(&bytes_dec_test[4], des_distance);
  Serial.write(bytes_dec_test, rcv_bytes_size);
  */
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
