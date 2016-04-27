#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <kernel/tty.h>

void kernel_launch(void)
{
	terminal_init();
	
	printf("\n\t\t\t\t\t\t\tWe have succesfully booted.\n\t\t\t\t\t\t\t\t\tWelcome to\n\t\t\t\t\t\t\t\t\t\tDevOS\n");
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
