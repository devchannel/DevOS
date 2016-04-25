#ifndef _GDT_H_
#define _GDT_H_

#include <stdint.h>

struct gdt_entry
{
	uint16_t 	low_limit;
	uint16_t 	low_base;
	
	uint8_t		middle_base;
	uint8_t		access;
	uint8_t		granularity;
	
	uint8_t		high_base
} __attribute__((packed));

struct gdt_ptr
{
	uint16_t	limit;
	uint32_t	base
} __attribute__((packed));




void init_descriptors();

#endif // _GDT_H_
