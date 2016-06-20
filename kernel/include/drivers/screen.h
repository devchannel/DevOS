#ifndef _KERNEL_SCREEN_H_
#define _KERNEL_SCREEN_H_

#include <stddef.h>


// Screen functions for writing
void terminal_init();
void terminal_putchar_at(char c, size_t x, size_t y);
void terminal_putchar(char c);

void kprint(const char* str);

// Screen functions for changing the view 
// TODO: Write and implement an interface for this
// EXAMPLE: terminal_change_background(Color background)

void clear();
#endif
