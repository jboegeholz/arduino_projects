import socket
import time
if __name__ == '__main__':

    bt_addr = '98:F4:AB:0E:DF:02'

    s = socket.socket(socket.AF_BLUETOOTH, socket.SOCK_STREAM, socket.BTPROTO_RFCOMM)
    s.connect((bt_addr, 1))
    print("Connected to Bluetooth")
    for i in range(100):
        s.send(b'On\n')
        time.sleep(1)
        s.send(b'Off\n')
        time.sleep(1)

    s.close()
