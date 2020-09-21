#ifndef INCLUDE_CONSOLE_H_
#define INCLUDE_CONSOLE_H_

#include "types.h"

typedef
enum real_color {
	rc_black = 0,
	rc_blue,
	rc_green,
	rc_cyan,
	rc_red,
	rc_mangenta,
	rc_brown,
	rc_light_grey,
	rc_dark_grey,
	rc_light_blue,
	rc_light_green,
	rc_light_cyan,
	rc_light_red,
	rc_light_magenta,
	rc_light_brown,
	rc_white
} real_color_t;

void console_clear();

void console_putc_color(char c, real_color_t back, real_color_t fore);

void console_write(char *cstr);

void console_write_color(char *cstr, real_color_t back, real_color_t fore);

void console_write_hex(uint32_t n, real_color_t back, real_color_t fore);

void console_write_dec(uint32_t n, real_color_t back, real_color_t fore);

#endif
