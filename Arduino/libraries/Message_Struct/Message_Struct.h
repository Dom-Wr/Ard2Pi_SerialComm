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
private:
  byte bytes[4];
};

#endif
