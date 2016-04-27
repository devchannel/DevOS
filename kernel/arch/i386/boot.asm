[BITS 32]

; Declare all the constants used in the multiboot header
MBALIGN equ 1<<0
MEMINFO equ  1<<1             	; provide memory map
FLAGS equ MBALIGN | MEMINFO 	; this is the Multiboot 'flag' field
MAGIC equ 0x1BADB002   		; 'magic number' lets bootloader find the header
CHECKSUM equ  -(MAGIC + FLAGS)  ; checksum of above, to prove we are multiboot

; Magic Values for the Bootloader
section .multiboot
align 4
dd MAGIC
dd FLAGS
dd CHECKSUM

section .bootstrap_stack, nobits ;Create a section for the stack

align 4
;Make a pointer to the bottom of the stack
stack_bottom:
resb 8192 ; Skip over 8KiB
stack_top:

section .text
global _start ; expose start
_start:
	; Now we're in Kernal Mode!
	; ASM is getting boring
	; Let's write some C!
	; To do that, we'll first setup our stack
	
	mov esp, stack_top
	
	; Launch Kernel before calling constructors
	extern kernel_launch
	call kernel_launch
	
	; Call C++ constructors
	extern _init
	call _init
	
	; Now we can call some C code.
	; Somewhere, (in kernel.c), we'll have a kernal_main function
	extern kernel_main
	call kernel_main
	
	; Disable interrupts and halt
	cli

.forever:
	hlt
	jmp .forever ; loop forever
; So cool, much wow

%include 'arch/i386/gdt.asm'
%include 'arch/i386/idt.asm'
