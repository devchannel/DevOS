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
	int orig = num;
	
	if(base < 2 || base > 35)
	{
		*str = '\0';	
		return str;
	}
	
	if(num < 0 && base == 10) num = -num;
	
	do
	{
		*_str = numbers[num % base > 0 ? num % base : -1 * num % base];
		_str++;
		
	} while((num /= base) != 0);
	
	if(orig < 0)
		*_str++ = '-';
		
	*_str = '\0';
	
	reverse(str, _str - 1);
	
	return str;
}
