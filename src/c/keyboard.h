#define USE_ANSI_ESCAPE 0
static void process_kbd_report(hid_keyboard_report_t const *report);
static void process_mouse_report(hid_mouse_report_t const *report);
static void process_generic_report(uint8_t dev_addr, uint8_t instance,
				   uint8_t const *report, uint16_t len);

void hid_app_task(void);
