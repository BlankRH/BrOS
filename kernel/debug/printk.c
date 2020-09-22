#include "console.h"
#include "vargs.h"
#include "string.h"
#include "debug.h"

static int vsprintf(char *buff, const char *format, va_list args);

// kernel print func
void printk(const char *format, ...) {
    static char buff[1024];
    va_list args;
    int i;

    va_start(args, format);
    i = vsprintf(buff, format, args);
    va_end(args);

    buff[i] = '\0';
    
    console_write(buff);
}

// kernel print func, with color
void printk_color(real_color_t back, real_color_t fore, const char *format, ...);