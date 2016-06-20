#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <drivers/screen.h>
#include <system.h>

void kernel_launch(void)
{
	terminal_init();
	init_gdt();
	init_idt();
	isrs_install();
	irq_install();
	
	asm volatile("sti");
	
	printf("\n\t\t\t\t\t\t\tWe have succesfully booted.\n\t\t\t\t\t\t\t\t\tWelcome to\n\t\t\t\t\t\t\t\t\t\tDevOS\n");
}

void kernel_main(void)
{
	printf("Foo bar");
	asm volatile("int $0x0");
}
