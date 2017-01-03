
import serial
import time
ser = serial.Serial('../../../dev/ttyACM12', 9600)
millis = .020
while 1 :
	ser.write('3')
	time.sleep(millis)
