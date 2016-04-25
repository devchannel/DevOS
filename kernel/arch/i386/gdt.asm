[GLOBAL gdt_flush]	; Allows C to link to us

; We get the GDT pointer passed as a parameter
gdt_flush:
	mov eax, [esp + 4]
	lgdt [eax]	; Load the GDT with out GDT pointer
	
	mov ax, 0x10	; Set the offset
	mov ds, ax		; proerply load the data segments
	mov fs, ax
	mov es, ax
	mov gs, ax
	mov ss, ax
	jmp 0x08:.flush
	
	
.flush:
	ret
