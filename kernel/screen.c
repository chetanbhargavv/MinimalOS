/* VGA text mode screen driver implementation */

#include "screen.h"
#include "types.h"

/* Screen state */
static uint16_t* vga_buffer = (uint16_t*)VGA_MEMORY;
static uint32_t cursor_x = 0;
static uint32_t cursor_y = 0;
static uint8_t current_color = 0x07;  /* Light grey on black */

/**
 * make_vga_entry - Create VGA character entry
 * @c: Character to display
 * @color: Color attribute
 * 
 * Returns: 16-bit VGA entry (character + color)
 */
static inline uint16_t make_vga_entry(char c, uint8_t color) {
    return (uint16_t)c | ((uint16_t)color << 8);
}

/**
 * make_color - Create color attribute byte
 * @fg: Foreground color
 * @bg: Background color
 * 
 * Returns: 8-bit color attribute
 */
static inline uint8_t make_color(uint8_t fg, uint8_t bg) {
    return fg | (bg << 4);
}

/**
 * screen_init - Initialize screen driver
 */
void screen_init(void) {
    cursor_x = 0;
    cursor_y = 0;
    current_color = make_color(COLOR_LIGHT_GREY, COLOR_BLACK);
}

/**
 * screen_scroll - Scroll screen up by one line
 */
static void screen_scroll(void) {
    /* Move all lines up */
    for (uint32_t y = 0; y < VGA_HEIGHT - 1; y++) {
        for (uint32_t x = 0; x < VGA_WIDTH; x++) {
            vga_buffer[y * VGA_WIDTH + x] = vga_buffer[(y + 1) * VGA_WIDTH + x];
        }
    }
    
    /* Clear last line */
    for (uint32_t x = 0; x < VGA_WIDTH; x++) {
        vga_buffer[(VGA_HEIGHT - 1) * VGA_WIDTH + x] = make_vga_entry(' ', current_color);
    }
    
    cursor_y = VGA_HEIGHT - 1;
}

/**
 * screen_clear - Clear entire screen
 */
void screen_clear(void) {
    for (uint32_t y = 0; y < VGA_HEIGHT; y++) {
        for (uint32_t x = 0; x < VGA_WIDTH; x++) {
            vga_buffer[y * VGA_WIDTH + x] = make_vga_entry(' ', current_color);
        }
    }
    cursor_x = 0;
    cursor_y = 0;
}

/**
 * screen_putchar - Print single character
 * @c: Character to print
 */
void screen_putchar(char c) {
    if (c == '\n') {
        cursor_x = 0;
        cursor_y++;
    } else if (c == '\r') {
        cursor_x = 0;
    } else if (c == '\t') {
        cursor_x = (cursor_x + 4) & ~3;
    } else if (c == '\b') {
        if (cursor_x > 0) {
            cursor_x--;
            vga_buffer[cursor_y * VGA_WIDTH + cursor_x] = make_vga_entry(' ', current_color);
        }
    } else {
        vga_buffer[cursor_y * VGA_WIDTH + cursor_x] = make_vga_entry(c, current_color);
        cursor_x++;
    }
    
    /* Handle line wrap */
    if (cursor_x >= VGA_WIDTH) {
        cursor_x = 0;
        cursor_y++;
    }
    
    /* Handle screen scroll */
    if (cursor_y >= VGA_HEIGHT) {
        screen_scroll();
    }
}

/**
 * screen_print - Print null-terminated string
 * @str: String to print
 */
void screen_print(const char* str) {
    if (!str) return;
    
    while (*str) {
        screen_putchar(*str);
        str++;
    }
}

/**
 * screen_println - Print string with newline
 * @str: String to print
 */
void screen_println(const char* str) {
    screen_print(str);
    screen_putchar('\n');
}

/**
 * screen_set_color - Set text color
 * @fg: Foreground color
 * @bg: Background color
 */
void screen_set_color(uint8_t fg, uint8_t bg) {
    current_color = make_color(fg, bg);
}
