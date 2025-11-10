/* VGA text mode screen driver */

#ifndef SCREEN_H
#define SCREEN_H

#include "types.h"

/* VGA text mode constants */
#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#define VGA_MEMORY 0xB8000

/* Color codes */
#define COLOR_BLACK 0
#define COLOR_BLUE 1
#define COLOR_GREEN 2
#define COLOR_CYAN 3
#define COLOR_RED 4
#define COLOR_MAGENTA 5
#define COLOR_BROWN 6
#define COLOR_LIGHT_GREY 7
#define COLOR_DARK_GREY 8
#define COLOR_LIGHT_BLUE 9
#define COLOR_LIGHT_GREEN 10
#define COLOR_LIGHT_CYAN 11
#define COLOR_LIGHT_RED 12
#define COLOR_LIGHT_MAGENTA 13
#define COLOR_YELLOW 14
#define COLOR_WHITE 15

/* Screen functions */
void screen_init(void);
void screen_clear(void);
void screen_putchar(char c);
void screen_print(const char* str);
void screen_println(const char* str);
void screen_set_color(uint8_t fg, uint8_t bg);

#endif
