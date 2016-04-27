#include "gdt.h"

/* defined in gdt.asm */
extern void gdt_flush();

static void gdt_set_gate(int num, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran);

/* Our actual GDT and pointer */
struct gdt_entry 	gdt[3];
struct gdt_ptr		gdt_p;

void init_gdt()
{
	gdt_p.limit = (sizeof(struct gdt_entry) * 3) - 1;
	gdt_p.base = (uint32_t) &gdt;
	
	gdt_set_gate(0, 0, 0, 0, 0); 					// Null GDT segment
	gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); 	// Code Segment
	gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF); 	// Data Segment
	
	gdt_flush();
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


