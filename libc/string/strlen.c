#include <string.h>

size_t strlen(const char* str)
{
	size_t size = 0;
	while(str[size])
		size++;
	return size;
}
