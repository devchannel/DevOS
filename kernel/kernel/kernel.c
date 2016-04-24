#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <kernel/tty.h>

void kernel_launch(void)
{
	terminal_init();
}

void kernel_main(void)
{
	printf("Some\nText\nHere\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nFoo\n");
}
