#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <kernel/tty.h>
#include <kernel/vga.h>

void __terminal_putentry(char c, uint8_t color, size_t x, size_t y)
{
	terminal_buffer[y * VGA_WIDTH + x] = make_vga_entry(c, color);
}


void terminal_init(void)
{
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = join_color(COLOR_LIGHT_GREY, COLOR_BLACK);
	terminal_buffer = (uint16_t*) 0xB8000;
	
	for(size_t y = 0; y < VGA_HEIGHT; y++)
	{
		for(size_t x = 0; x < VGA_WIDTH; x++)
		{
			__terminal_putentry(' ', terminal_color, x, y);
		} // End for
	} // End for
}

void __terminal_scroll()
{
	for(size_t row = 1; row < VGA_HEIGHT; row++)
		memmove((terminal_buffer + ((row - 1) * VGA_WIDTH)), (terminal_buffer + (row * VGA_WIDTH)), VGA_WIDTH);
	
	for(size_t i = 0; i < VGA_WIDTH; i++)
		__terminal_putentry(' ', terminal_color, i, VGA_HEIGHT - 1);
	
	terminal_column = 0;
	terminal_row = VGA_HEIGHT - 1;
}

void terminal_putchar(char c)
{
	switch (c)
	{
		case '\n':
			terminal_column = 0;
			if(++terminal_row == VGA_HEIGHT)
				__terminal_scroll();
			break;
		case '\t':
			for(size_t i = 0; i < 4; i++)
			{
				__terminal_putentry(' ',terminal_color,terminal_column, terminal_row);
				if(++terminal_column == VGA_WIDTH)
				{
					if(++terminal_row == VGA_HEIGHT)
						__terminal_scroll();
				}
			}
			break;
		default:
			__terminal_putentry(c, terminal_color, terminal_column, terminal_row);
			if(++terminal_column == VGA_WIDTH)
			{
				terminal_column = 0;
				if(++terminal_row == VGA_HEIGHT)
					__terminal_scroll();
			}
			break;
	}
}

void kprint(const char* str)
{
	size_t size = strlen(str);

	for(size_t i = 0; i < size; i++)
		terminal_putchar(str[i]); 
}
