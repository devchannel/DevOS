#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

static void print(const char* str, size_t len)
{
	for(size_t i = 0; i < len; i++)
		putchar((int) ((const unsigned char*) str)[i]);
}

int printf(const char* restrict format, ...)
{

	va_list parameters;
	va_start(parameters, format);
	
	//print("We're in printf", strlen("We're in printf"));
	
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
