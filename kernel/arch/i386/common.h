#ifndef _COMMON_H_
#define _COMMON_H_

#include <stdint.h>

struct registers
{
	unsigned int gs, fs, es, ds; // This is pushed last
	unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax; // These are pushed by pusha
	unsigned int int_num, err_code; // Stuff we push when calling
	unsigned int eip, cs, eflags, useresp, ss; // Stuff that is pushed bu the processor
};

static inline void outb(uint16_t port, uint8_t val)
{
    asm volatile ( "outb %0, %1" : : "a"(val), "Nd"(port) );
}

static inline uint8_t inb(uint16_t port)
{
    uint8_t ret;
    asm volatile ( "inb %1, %0"
                   : "=a"(ret)
                   : "Nd"(port) );
    return ret;
}

static inline void io_wait(void)
{
    /* Port 0x80 is used for 'checkpoints' during POST. */
    /* The Linux kernel seems to think it is free for use :-/ */
    asm volatile ( "outb %%al, $0x80" : : "a"(0) );
    /* %%al instead of %0 makes no difference.  TODO: does the register need to be zeroed? */
}

#endif
