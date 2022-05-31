#include "i2c.h"
#include <Arduino.h>
#include <Wire.h>

void i2c_setup(void (*recv_callback)(int), void (*req_callback)(void))
{
	Wire1.setSDA(2);
	Wire1.setSCL(3);
	gpio_pull_up(2);
	gpio_pull_up(3);
	Wire1.begin(0x69);
	i2c_receive(recv_callback);
	i2c_request(req_callback);
}

void i2c_receive(void (*callback)(int))
{
	Wire1.onReceive(callback);
}

void i2c_request(void (*callback)(void))
{
	Wire1.onRequest(callback);
}

void i2c_read()
{
	Wire1.read();
}

void i2c_write(uint8_t *send, int len = 32)
{
	Wire1.write(send, len);
}
