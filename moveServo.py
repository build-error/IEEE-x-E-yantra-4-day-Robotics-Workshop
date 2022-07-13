import struct
import serial
import struct

ser = serial.Serial('COM3', timeout = 1)

pos = 0
ser.write(pos)
while pos <= 90:
    pos = pos + 0.1
    bytePos = bytearray(struct.pack("f", pos))
    ser.write(bytePos)

