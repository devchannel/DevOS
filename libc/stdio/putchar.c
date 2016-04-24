#include <string.h>

#if defined(__DevOS_Kernel_)
#	include <kernel/tty.h>
#endif

int putchar(int c)
{
	#if defined(__DevOS_Kernel_)
		terminal_putchar(c);
	#else
	//TODO: Something here
	#endif
	return c;
}
