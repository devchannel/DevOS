#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

void reverse(char* start, char* end)
{
	while(start < end)
	{
		char temp = *start;
		*start = *end;
		*end = temp;
		
		
		start++;
		end--;
	}	
}

char* itoa(int num, int base, char* str)
{
	static char numbers[] = "0123456789abcdefghijklmnopqrstuv";
	char* _str = str;
	
	if(base < 2 || base > 35)
	{
		*str = '\0';	
		return str;
	}
	
	do
	{
		*_str = numbers[num % base > 0 ? num % base : -1 * num % base];
		_str++;
		
	} while((num /= base) != 0);
	
	reverse(str, _str - 1);
	
	return str;
}
