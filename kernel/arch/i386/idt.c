#include "idt.h"

#include <string.h> // memset

extern void idt_flush(); // Defined in idt.asm

struct idt_entry idt[256];
struct idt_ptr idt_p;

void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags)
{
	idt[num].base_low = 	(base & 0xFFFF);
	idt[num].base_high = 	(base >> 16) & 0xFF;
	
	idt[num].sel = 			sel;
	
	idt[num].zero = 		0;
	idt[num].flags = 		flags;
}

void init_idt()
{
	// Give our pointer some details
	idt_p.limit = (sizeof(struct idt_entry) * 256) - 1;
	idt_p.base = (uint32_t)&idt;
	
	memset(&idt, 0, sizeof(struct idt_entry) * 256);
	
	idt_flush();	
}
