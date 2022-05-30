#include "pico/stdlib.h"
#include <stdio.h>
#include <Wire.h>
#include <tusb.h>

void recv(int len);
void req();

int main()
{
	// stdio_init_all();
	// while (!stdio_usb_connected()) {
	//         printf(".");
	//         sleep_ms(500);
	// }
	// puts("USB host connected!\n");
	//
	Wire1.setSDA(2);
	Wire1.setSCL(3);
	gpio_pull_up(2);
	gpio_pull_up(3);
	Wire1.begin(0x69);
	Wire1.onReceive(recv);
	Wire1.onRequest(req);

	tusb_init();

	while (true) {
		delay(1000);
	}
}

void recv(int len)
{
	for (int i = 0; i < len; i++)
		Wire1.read();
}

void req()
{
}
