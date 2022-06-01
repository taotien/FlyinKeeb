#include <bsp/rp2040/board.h>
#include <tusb.h>

#include "keyboard.h"

#define MAX_REPORT 4

static struct {
	uint8_t report_count;
	tuh_hid_report_info_t report_info[MAX_REPORT];
} hid_info[CFG_TUH_HID];

void hid_app_task(void)
{
}

void tuh_hid_mount_cb(uint8_t dev_addr, uint8_t instance,
		      uint8_t const *desc_report, uint16_t desc_len)
{
	// Interface protocol (hid_interface_protocol_enum_t)
	const char *protocol_str[] = { "None", "Keyboard", "Mouse" };
	uint8_t const itf_protocol =
		tuh_hid_interface_protocol(dev_addr, instance);
	if (itf_protocol == HID_ITF_PROTOCOL_NONE) {
		hid_info[instance].report_count =
			tuh_hid_parse_report_descriptor(
				hid_info[instance].report_info, MAX_REPORT,
				desc_report, desc_len);
	}

	// request to receive report
	// tuh_hid_report_received_cb() will be called when report is available
	if (!tuh_hid_receive_report(dev_addr, instance)) {
	}
}

void tuh_hid_umount_cb(uint8_t dev_addr, uint8_t instance)
{
}

void tuh_hid_report_received_cb(uint8_t dev_addr, uint8_t instance,
				uint8_t const *report, uint16_t desc_len)
{
	uint8_t const itf_protocol =
		tuh_hid_interface_protocol(dev_addr, instance);
	switch (itf_protocol) {
	case HID_ITF_PROTOCOL_KEYBOARD:
		process_kbd_report((hid_keyboard_report_t const *)report);
		break;
	case HID_ITF_PROTOCOL_MOUSE:
		// process_mouse_report((hid_mouse_report_t const *)report);
		break;
	default:
		// process_generic_report(dev_addr, instance, report, len);
		break;
	}
	if (!tuh_hid_receive_report(dev_addr, instance)) {
	}
}

static inline bool find_key_in_report(hid_keyboard_report_t const *report,
				      uint8_t keycode)
{
	for (uint8_t i = 0; i < 6; i++) {
		if (report->keycode[i] == keycode)
			return true;
	}
	return false;
}

static void process_kbd_report(hid_keyboard_report_t const *report)
{
	static hid_keyboard_report_t prev_report = { 0, 0, { 0 } };
	for (uint8_t i = 0; i < 6; i++) {
		if (report->keycode[i]) {
			if (find_key_in_report(&prev_report,
					       report->keycode[i])) {
				// key is held
			} else {
				printf("%d", report->keycode[i]);
				fflush(stdout);
			}
		}
	}
	// TODO implement key released
	prev_report = *report;
}
