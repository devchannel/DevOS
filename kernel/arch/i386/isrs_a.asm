%macro	ISR_NOERR 1
	[GLOBAL isr%1]
	isr%1:
		cli
		push byte 0

		push byte %1
		jmp isr_common_stub
%endmacro

%macro ISR_ISERR 1
	[GLOBAL isr%1]
	isr%1:
		cli
		
		push byte %1
		jmp isr_common_stub
%endmacro

ISR_NOERR 0
ISR_NOERR 1
ISR_NOERR 2
ISR_NOERR 3
ISR_NOERR 4
ISR_NOERR 5
ISR_NOERR 6
ISR_NOERR 7
ISR_ISERR 8
ISR_NOERR 9
ISR_ISERR 10
ISR_ISERR 11
ISR_ISERR 12
ISR_ISERR 13
ISR_ISERR 14
ISR_NOERR 15
ISR_NOERR 16
ISR_NOERR 17
ISR_NOERR 18
ISR_NOERR 19
ISR_NOERR 20
ISR_NOERR 21
ISR_NOERR 22
ISR_NOERR 23
ISR_NOERR 24
ISR_NOERR 25
ISR_NOERR 26
ISR_NOERR 27
ISR_NOERR 28
ISR_NOERR 29
ISR_NOERR 30
ISR_NOERR 31

extern int_handler
isr_common_stub:
	pusha
	push ds
	push es
	push fs
	push gs
	
	mov ax, 0x10 ; Load the kernel data segment
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	
	mov eax, esp
	push eax
	
	mov eax, int_handler
	call eax
	pop eax
	pop gs
	pop fs
	pop es
	pop ds
	
	popa
	
	add esp, 8
	iret
