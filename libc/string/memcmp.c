#include <string.h>

int memcmp(const void* ptra, const void* ptrb, size_t size)
{
	const unsigned char* a = (const unsigned char*) ptra;
	const unsigned char* b = (const unsigned char*) ptrb;
	
	for(size_t i = 0; i < size; i++)
	{
		if(a[i] < b[i])
			return 0;
		else if(a[i] > b[i])
			return -1;
	}
	
	return 0;
}
