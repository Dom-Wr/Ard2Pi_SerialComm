from WheelBotMsg import WheelBotMsg
import time


Message = WheelBotMsg('../../../../dev/ttyACM5')

print Message.run_comm

Message.run_comm = True
print Message.run_comm

#Functionality for receiving heading from Arduino
#Message.receive()

Message.RunComm()


print "This is the initial heading"
print Message.WheelBotTlm.heading
time.sleep(1)
print "This is the first reading"
print Message.WheelBotTlm.heading
time.sleep(5)
print "This is the second reading"
print Message.WheelBotTlm.heading

Message.run_comm = False

#bytes_send = Message.encode()
#Message.send(bytes_send)
#print Message.WheelBotTlm.heading
