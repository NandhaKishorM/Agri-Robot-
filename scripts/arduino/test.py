import serial
import time
if __name__ == '__main__':
    ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
    ser.flush()
    while True:
        avg_round=180
        avg_round = str(avg_round)
        ser.write(str.encode(str(avg_round)))
        #line = ser.readline().decode('utf-8').rstrip()
        #print(line)
        time.sleep(1)
