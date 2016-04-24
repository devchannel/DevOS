#include <string.h>

void* memset(void* str, int c, size_t n)
{
	unsigned char* buffer = (unsigned char*) str;
	
	for(size_t i = 0; i < n; i++)
		buffer[i] = (unsigned char) c;
	return str;
}
