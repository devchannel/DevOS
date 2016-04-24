#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <kernel/tty.h>

void kernel_launch(void)
{
	terminal_init();
	printf("Welcome to DevOS. We have succesfully booted and loaded.\n\n");
}

void kernel_main(void)
{

	int a = 1;
	int b = 1;
	
	printf("Computing the first 10 fibonacci numbers\n");
	
	printf("%d\n%d\n", a, b);
	
	for(int i = 0; i < 8; i++)
	{
		int temp = a;
		a = a + b;
		b = temp;
		
		printf("%d\n", a);
	}
}
