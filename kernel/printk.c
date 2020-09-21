#include "console.h"
#include "vargs.h"

// kernel print func
void printk(const char *format, ...);

// kernel print func, with color
void printk_color(real_color_t back, real_color_t fore, const char *format, ...);