; Interrupt Descriptor Table

global idt_flush
extern idt_p

idt_flush:
	lidt [idt_p]
	ret

