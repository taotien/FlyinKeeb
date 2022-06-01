#include <stdint.h>

void i2c_receive_callback(int len);
void i2c_request_callback();
extern void i2c_setup(void (*recv_callback)(int), void (*req_callback)(void));
extern void i2c_read();
extern void i2c_write(uint8_t *send, unsigned int len);
void tuh_mount_cb(uint8_t dev_addr);
void tuh_unmount_cb(uint8_t dev_addr);
