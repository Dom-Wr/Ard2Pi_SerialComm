#This is the Wheelbot Message class

import serial
from struct import *
import time


class WheelBotMsg:
    def __init__(self, ArduinoLoc):
        self.WheelBotCmds = WheelBotCmds()
        self.WheelBotTlm = WheelBotTlm()
        self.ArduinoLoc = ArduinoLoc
        self.ser = serial.Serial(ArduinoLoc, 9600)
        self.rcv_flag = False
        self.bytes_rcv = []
        self.bytes_send = []


    def receive(self):
        #functionality for receiving information

        #frequency of reading from Arduino in seconds
        frequency = .020
        start_time = time.time()

        while self.rcv_flag == True :
            self.ser.write('1') #Tells Arduino to send heading
            while self.ser.in_waiting > 0:
                print "Serial port is in waiting"
                start_time = time.time()
                bytes_rcv = self.ser.read(4)
                print "This is 4 bytes",
                print bytes_rcv

                print "End of 4 bytes"

                print ''.join( [ "%02X " % ord( x ) for x in bytes_rcv]).strip()

                self.decode(bytes_rcv)


            time.sleep(frequency)
            print("--- %s seconds ---" % (time.time() - start_time))



    def decode(self, bytes_rcv):
        #functionality for decoding bytes received from Serial port

        #if the value is a float value
        self.WheelBotTlm.heading = unpack(self.WheelBotTlm.bytes_rcv_form, bytes_rcv)

        print "This is the heading:",
        print self.WheelBotTlm.heading
        #if the value is a int value

    def encode(self):
        #functionality for encoding data into bytes that will be sent
        bytes_send = pack(self.WheelBotCmds.bytes_send_form, self.WheelBotCmds.cmd1,
             self.WheelBotCmds.kp, self.WheelBotCmds.ki, self.WheelBotCmds.kd)

        print ''.join( [ "%02X " % ord( x ) for x in bytes_send]).strip()
        return bytes_send


    def send(self, bytes_snd):
        #function for sending messages back to the Arduino
        self.ser.write(bytes_snd)

class WheelBotCmds:
    def __init__(self):
        self.cmd1 = 324
        self.kp = 1.234
        self.ki = 1.234
        self.kd = 1.234
        self.bytes_send_form = '<ifff'

class WheelBotTlm:
    def __init__(self):
        self.heading = 0
        self.bytes_rcv_form = '<f'
