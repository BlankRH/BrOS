#include "console.h"


int kern_entry() {

	console_clear();

	console_write_dec(12345, rc_black, rc_green);

	console_write("\nhex:\n");

	console_write_hex(0x12345, rc_black, rc_blue);

	return 0;
}
