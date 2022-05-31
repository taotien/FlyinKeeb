#include <stdint.h>

extern "C" void i2c_setup(void (*recv_callback)(int),
			  void (*req_callback)(void));
void i2c_receive(void (*callback)(int));
void i2c_request(void (*callback)(void));
extern "C" void i2c_read();
extern "C" void i2c_write(uint8_t *send, int len);
