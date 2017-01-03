#ifndef MESSAGE_STRUCT_HH
#define MESSAGE_STRUCT_HH

#include "Arduino.h"

class Message_Struct
{
public:
  Message_Struct();
  void EncodeMagn(double heading);
  double DecodeMagn();
  void send();
  void receive();
private:
  byte bytes_send[4];
  byte bytes_receive[];
  unsigned char incom_byte_form[];
};

#endif
