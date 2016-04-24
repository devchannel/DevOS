#include <string.h>

void* memmove(void* dstp, const void* srcp, size_t size)
{
	unsigned char* dst = (unsigned char*) dstp;
	const unsigned char* src = (const unsigned char*) srcp;
	if ( dst < src )
		for ( size_t i = 0; i < size; i++ )
			dst[i] = src[i];
	else
		for ( size_t i = size; i != 0; i-- )
			dst[i-1] = src[i-1];
	return dstp;
}
