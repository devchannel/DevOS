#include <string.h>

#include <drivers/screen.h>

int putchar(int c)
{
	terminal_putchar(c);
	return c;
}
