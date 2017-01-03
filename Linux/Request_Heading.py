import serial
from struct import *
import time
#import datetime
ser = serial.Serial('../../../dev/ttyACM16', 9600)
millis = .020


start_time = time.time()

while 1 :

    #if enough time has passed then tell Arduino to send heading

    ser.write('1')
    while ser.in_waiting > 0:
        start_time = time.time()
        val1_bytes = ser.read(4)
        print "This is 4 bytes",
        print val1_bytes

        print "End of 4 bytes"

        print ''.join( [ "%02X " % ord( x ) for x in val1_bytes]).strip()

        a = unpack('<f', val1_bytes)

        print "This is 'a':",
        print a

    time.sleep(millis)
    print("--- %s seconds ---" % (time.time() - start_time))
