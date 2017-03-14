#ifndef MESSAGE_STRUCT_HH
#define MESSAGE_STRUCT_HH

#include "Arduino.h"

class Message_Struct
{
public:
  Message_Struct();
  void RunComm();
  void setHeading(double _heading);
  void setDistance(double _distance);

  void EncodeMagn();

  double Decode();
  void send();
  void receive();
  //int num_bytes = 0;
private:
  double heading;
  double distance;
  byte bytes_send[256];
  unsigned char bytes_receive[256];
  int rcv_bytes_size;
  unsigned char incom_byte_form[];
};

#endif
