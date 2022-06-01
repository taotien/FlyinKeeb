#include <pico/stdlib.h>
#include <stdio.h>
#include <time.h>
#include <bsp/rp2040/board.h>
#include <tusb.h>

#include "main.h"

int main()
{
	stdio_init_all();
	// while (!stdio_usb_connected()) {
	//         printf(".");
	//         sleep_ms(500);
	// }
	// puts("USB host connected!\n");
	i2c_setup(i2c_receive_callback, i2c_request_callback);
	tusb_init();

	while (1) {
		tuh_task();
	}
}

void i2c_receive_callback(int len)
{
	for (int i = 0; i < len; i++)
		i2c_read();
}

void i2c_request_callback()
{
}

void tuh_mount_cb(uint8_t dev_addr)
{
}

void tuh_umount_cb(uint8_t dev_addr)
{
}
