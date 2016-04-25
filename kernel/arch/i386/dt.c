#include "dt.h"

/* defined in gdt.asm */
extern void gdt_flush(uint32_t);

static void init_gdt();
static void gdt_set_gate(int num, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran);

/* Our actual GDT and pointer */
struct gdt_entry 	gdt[5];
struct gdt_ptr		gdt_p;

void init_descriptors()
{
	init_gdt();
}

static void init_gdt()
{
	gdt_p.limit = (sizeof(struct gdt_entry) * 5) - 1;
	gdt_p.base = (uint32_t) &gdt;
	
	gdt_set_gate(0, 0, 0, 0, 0); 				// Null GDT segment
	gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0); 	// Code Segment
	gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0); 	// Data Segment
	gdt_set_gate(3, 0, 0xFFFFFFFF, 0xFA, 0);	// User mode Code Segment
	gdt_set_gate(4, 0, 0xFFFFFFFF, 0xF2, 0);	// User mode Data Segment
	
	gdt_flush((uint32_t) &gdt_p);
}

static void gdt_set_gate(int num, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran)
{
	gdt[num].low_base 		= (base & 0xFFFF);
	gdt[num].middle_base	= (base >> 16) & 0xFF;
	gdt[num].high_base		= (base >> 24) & 0xFF;
	
	gdt[num].low_limit 		= (limit & 0xFFFF);
	gdt[num].granularity	= (limit >> 16) & 0x0F;
	
	gdt[num].granularity   |= gran & 0xF0;
	gdt[num].access 		= access;
}


