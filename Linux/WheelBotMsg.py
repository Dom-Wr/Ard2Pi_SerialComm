#This is the Wheelbot Message class

import serial
from struct import *
import time
import csv
import threading
import math


class WheelBotMsg:
    def __init__(self, ArduinoLoc):
        self.WheelBotCmds = WheelBotCmds()
        self.WheelBotTlm = WheelBotTlm()
        self.ArduinoLoc = ArduinoLoc
        self.ser = serial.Serial(ArduinoLoc, 9600)

        self.csvfile = open('heading.csv', 'wb')
        self.writer = csv.writer(self.csvfile)
        self.rowlogcounter = 0
        self.log_frequency = .5

        self.run_comm = False
        self.snd_cmds = False
        self.data_logging = False
        self.bytes_rcv = []
        self.bytes_send = []



    def receive(self):
        #functionality for receiving information

        #frequency of reading from Arduino in seconds
        print "The receive function is running"

        frequency = 2.00
        #log_frequency = 3
        start_time = time.time()
        log_time = time.time()

        while self.run_comm == True :
            #self.ser.write('1') #Tells Arduino to send heading
            self.send()
            #print "Arduino has been told to send heading"
            print self.ser.in_waiting
            while self.ser.in_waiting > 0:
                print "Serial port is in waiting"
                start_time = time.time()
                num_bytes = self.ser.in_waiting
                bytes_rcv = self.ser.read(num_bytes)
                print num_bytes
                print "Bytes received",
                print bytes_rcv


                print ''.join( [ "%02X " % ord( x ) for x in bytes_rcv]).strip()

                self.decode(bytes_rcv)

                if self.data_logging == True:
                    if self.rowlogcounter < 20:
                        if ((time.time() - log_time) >= self.log_frequency):
                            self.log_data()
                            self.rowlogcounter += 1
                            log_time = time.time()

            time.sleep(frequency)
            #self.send()
            print("--- %s seconds ---" % (time.time() - start_time))


    def decode(self, bytes_rcv):
        #functionality for decoding bytes received from Serial port

        #if the value is a float value
        raw_data_tuple = unpack(self.WheelBotTlm.bytes_rcv_form, bytes_rcv)
        #print type(raw_data_tuple)
        self.WheelBotTlm.heading = raw_data_tuple[0]
        self.WheelBotTlm.distance = raw_data_tuple[1]

        #print "This is the decode heading:",
        print self.WheelBotTlm.heading
        print self.WheelBotTlm.distance
        #if the value is a int value

    def log_data(self):
        #print "Data log function running"
        #print self.data_logging
        multifact = 180.0/math.pi
        heading_deg = self.WheelBotTlm.heading * 180.0/math.pi
        csv_row = [str(heading_deg), str(self.WheelBotTlm.heading)]
        self.writer.writerow(csv_row)
        #print "logging data"

    def encode(self):
        #functionality for encoding data into bytes that will be sent
        bytes_send = pack(self.WheelBotCmds.bytes_send_form, self.WheelBotCmds.cmd1,
             self.WheelBotCmds.kp, self.WheelBotCmds.ki, self.WheelBotCmds.kd)

        print ''.join( [ "%02X " % ord( x ) for x in bytes_send]).strip()
        return bytes_send


    def send(self):
        #function for sending messages back to the Arduino
        print "Message Send run"
        #while self.snd_cmds == True :

        #print "Send is running"
        #self.ser.write('2')

        floatval = 1.234
        bytes_snd = pack('<ff',floatval, floatval+5.0 )
        print "Float to send",
        print bytes_snd

        print ''.join( [ "%02X " % ord( x ) for x in bytes_snd]).strip()
        self.ser.write(bytes_snd)

    def RunComm(self):
        #function for starting Comm on a separate thread
        #print "RunComm is running"
        #self.send()

        t = threading.Thread(target=self.receive)
        t.daemon = True
        t.start()
        #print t.isAlive()


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
        self.distance = 0
        self.bytes_rcv_form = '<ff'
