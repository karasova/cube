import serial 
import numpy as np
import struct

ser = serial.Serial('COM3', 9600)

# array = np.zeros((3, 3, 3), dtype = np.int8)

# array [0:, 1, 1] = 1



a = "AB\n"
final = a.encode("utf-8")

while True: 
    ser.write(final)

