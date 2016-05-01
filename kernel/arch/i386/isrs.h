#ifndef _ISRS_H_
#define _ISRS_H_

struct registers
{
	unsigned int gs, fs, es, ds; // This is pushed last
	unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax; // These are pushed by pusha
	unsigned int int_num, err_code; // Stuff we push when calling
	unsigned int eip, cs, eflags, useresp, ss; // Stuff that is pushed bu the processor
};

void isrs_install();

#endif
