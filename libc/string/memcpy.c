#include <string.h>

void* memcpy(void* restrict dstp, const void* restrict srcp, size_t size)
{
	unsigned char* dst = (unsigned char*) dstp;
	const unsigned char* src = (const unsigned char*) srcp;
	
	for(size_t i = 0; i < size; i++)
		dst[i] = src[i];
	return dstp;
}
