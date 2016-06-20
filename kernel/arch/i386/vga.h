#ifndef _KERNEL_VGA_H_
#define _KERNEL_VGA_H_

/* Basic constants */
static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
static const size_t VGA_MEMORY = (uint16_t) 0xb8000;

/* Global Variables */

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer;

enum vga_color
{
	COLOR_BLACK = 0,
	COLOR_BLUE = 1,
	COLOR_GREEN = 2,
	COLOR_CYAN = 3,
	COLOR_RED = 4,
	COLOR_MAGENTA = 5,
	COLOR_BROWN = 6,
	COLOR_LIGHT_GREY = 7,
	COLOR_DARK_GREY = 8,
	COLOR_LIGHT_BLUE = 9,
	COLOR_LIGHT_GREEN = 10,
	COLOR_LIGHT_CYAN = 11,
	COLOR_LIGHT_RED = 12,
	COLOR_LIGHT_MAGENTA = 13,
	COLOR_LIGHT_BROWN = 14,
	COLOR_WHITE = 15,
};

static inline uint8_t join_color(enum vga_color fg, enum vga_color bg)
{
	return fg | bg << 4;
}

inline uint16_t make_vga_entry(char c, uint8_t color)
{
	uint16_t c16 = c;
	uint16_t color16 = color;
	return c16 | color16 << 8;
}

static inline void set_terminal_color(enum vga_color fg, enum vga_color bg)
{
	terminal_color = join_color(fg, bg);
}

#endif
