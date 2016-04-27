; Global Descriptor Table

global gdt_flush
extern gdt_p ; The GDT pointer from the C file

gdt_flush:
	lgdt [gdt_p]	; Load the GDT with out GDT pointer
	
	mov ax, 0x10	; Set the offset
	mov ds, ax		; proerply load the data segments
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax
	jmp 0x08:flush2
	
flush2:
	ret
