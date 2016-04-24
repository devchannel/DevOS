#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

static void print(const char* str, size_t len)
{
	for(size_t i = 0; i < len; i++)
		putchar((int) ((const unsigned char*) str)[i]);
}

static int print_num(int num, int base)
{
	static char num_holder[19]; // Big enough to hold a 64 bit int
	
					
	char* number = itoa(num, base, num_holder);
	int size = strlen(number);
	print(number, size);
	return size;
}

int printf(const char* restrict format, ...)
{

	va_list parameters;
	va_start(parameters, format);
	
	int written = 0;
		
	while(*format != '\0')
	{
		if(*format == '%')
		{
			switch(*(++format))
			{
				case 'c':
					;
					char c = va_arg(parameters, int);
					print(&c, sizeof(c));
					written++;
					break;
				case 's':
					;
					const char* str = va_arg(parameters, const char*);
					int size = strlen(str);
					print(str, size);
					written += size;
					break;
				case 'i':
				case 'd':
					written += print_num(va_arg(parameters, int), 10);
					break;
				
				case 'x':
				case 'X':
					written += print_num(va_arg(parameters, int), 16);
					break;
				
				case 'o':
					written += print_num(va_arg(parameters, int), 8);
					break;
				
				default:
					break;
			}
			
			format++;
		} else {
			written++;
			print(format, 1);
			format++;
		}
	}
	va_end(parameters);
	return written;
}
