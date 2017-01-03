from WheelBotMsg import WheelBotMsg


Message = WheelBotMsg('../../../dev/ttyACM2')

print Message.rcv_flag

Message.rcv_flag = True
print Message.rcv_flag

#Functionality for receiving heading from Arduino
Message.receive()


#bytes_send = Message.encode()
#Message.send(bytes_send)
#print Message.WheelBotTlm.heading
