#include <stdio.h>
#include <stdlib.h>

__attribute__((__noreturn__))
void abort(void)
{
	// TODO: Add proper kernel panic.
	printf("PANIC!!!!!!!!!!!!!! Abort all stations!\n");
	while ( 1 ) { }
	__builtin_unreachable();
}
