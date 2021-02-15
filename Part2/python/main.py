import pyautogui
import serial

threshold = 1010
ser = serial.Serial(port='COM8', baudrate=9600)

try: 
    while 1:
        line = ser.readline()
        print(line)
        raw = str(line, 'utf-8').replace('\r\n', '').split(' ')
        print(raw[1])

        if float(raw[1]) > threshold:
            pyautogui.press('space')

except Exception as e:
    print("error: " + str(e))

