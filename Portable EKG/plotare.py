import time

import matplotlib.pyplot as plt
import serial
from numpy import arange



def isfloat(num):
    try:
        float(num)
        return True
    except ValueError:
        return False


plt.ion()
plt.figure(figsize=(5,5))
plt.xlabel("Time")
plt.ylabel("Sinus")
plt.ylim(200,550)
plt.grid()
x = list()
y = list()
ser = serial.Serial("COM5", 9600)
ser.close()
ser.open()


for timp in arange(0.0,30.0,0.1):
    data = ser.readline()
    print(data.decode())
    
    if isfloat(data.decode()):
        x.append(timp)
        y.append(float(data.decode()))
        plt.plot(x,y)
    elif(data.decode()=="F\n"):
            m = []
            s = 0
            for i in range(len(y) - 1):
                m.append(y[i + 1] - y[i])
            s = sum(m)
            print(s)
            time.sleep(1)
            if(s<0):
                ser.write('a'.encode())
            else:
                ser.write('b'.encode())
            print("Vezi ca se transmite invers!")


    plt.pause(0.05)
    plt.show()
    plt.savefig('ekg.png')
