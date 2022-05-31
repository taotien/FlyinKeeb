#include "main.h"
#include <stdio.h>
#include <pico/stdlib.h>

int main()
{
	// stdio_init_all();
	// while (!stdio_usb_connected()) {
	//         printf(".");
	//         sleep_ms(500);
	// }
	// puts("USB host connected!\n");
	i2c_setup(i2c_receive_callback, i2c_request_callback);

	while (1) {
		sleep_ms(500);
		// tuh_task();
	}
}

void i2c_receive_callback(int len)
{
	for (int i = 0; i < len; i++)
		i2c_read();
}

void i2c_request_callback()
{
	i2c_write("owo", 32);
}
