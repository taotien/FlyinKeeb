#include <stdio.h>
#include <time.h>
#include <pico/stdlib.h>
#include <hardware/i2c.h>
#include <bsp/rp2040/board.h>
#include <tusb.h>

#include "main.h"
#include "keyboard.h"

int main()
{
	stdio_init_all();
	// while (!stdio_usb_connected()) {
	//         printf(".");
	//         sleep_ms(500);
	// }
	// puts("USB host connected!\n");

	i2c_init(i2c_default, 400 * 1000);
	gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
	gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);
	gpio_pull_up(PICO_DEFAULT_I2C_SDA_PIN);
	gpio_pull_up(PICO_DEFAULT_I2C_SCL_PIN);

	tusb_init();

	while (1) {
		tuh_task();
	}
}

void tuh_mount_cb(uint8_t dev_addr)
{
}

void tuh_umount_cb(uint8_t dev_addr)
{
}
