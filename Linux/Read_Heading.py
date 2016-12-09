import serial
from struct import *

#Change the device name as needed for your Arduino
ser = serial.Serial('/dev/ttyACM0', 9600)

while 1 :
    #val1_bytes = ser.readline()

    #
    while ser.in_waiting > 0:
        val1_bytes = ser.read(4)
        print "This is 4 bytes",
        print val1_bytes
    #
        print "End of 4 bytes"

        print ''.join( [ "%02X " % ord( x ) for x in val1_bytes]).strip()

        a = unpack('<f', val1_bytes)

        print "This is 'a':",
        print a
