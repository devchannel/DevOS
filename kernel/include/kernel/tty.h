#ifndef _KERNEL_TTY_H_
#define _KERNEL_TTY_H_

#include <stddef.h>

void terminal_init();
void terminal_putchar(char c);

void kprint();

void clear();
#endif
