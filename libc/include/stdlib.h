#ifndef _STDLIB_H_
#define _STDLIB_H_ 1

#include <sys/cdefs.h>

#ifdef __cplusplus
	extern "C" {
#endif

char* itoa(int num, int base, char* str);

__attribute__((__noreturn__))
void abort(void);

#ifdef __cplusplus
	}
#endif

#endif // _STDLIB_H_
