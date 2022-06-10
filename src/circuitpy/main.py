import board
from i2cperipheral import I2CPeripheral
import busio
from time import sleep
from binascii import hexlify

uart = busio.UART(board.GP0, board.GP1, baudrate=115200)
print('owo')
i2c = I2CPeripheral(bus=1, sclPin=3, sdaPin=2, address=0x69)
data = bytearray(6)

while True:
    if not i2c.have_recv_req():
#         print('norecv')
#         sleep(1)
        continue

    else:
        i2c.recv(data)
        print(hexlify(data))