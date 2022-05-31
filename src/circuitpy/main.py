import board
from time import sleep

i2c = None

while not i2c:
    try:
        i2c = board.I2C()
    except:
        print("waiting for i2c device")
        sleep(1)
        pass

while not i2c.try_lock():
    pass

try:
    #  devices = i2c.scan()
    #  print(devices[0])
    res = bytearray(4)
    while True:
        i2c.readfrom_into(0x69, res)
        print(res.decode())
        sleep(1)

    
finally:
    i2c.unlock()
