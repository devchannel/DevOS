#include <stdio.h>
#include <string.h>

#if defined(__DevOS_Kernel_)
#	include <kernel/tty.h>
#endif

int puts(const char* str)
{
	#if defined(__DevOS_Kernel_)
		kprint(str);
		kprint("\n");
	#else
	//TODO: Something here
	#endif
	
	return strlen(str);
}
