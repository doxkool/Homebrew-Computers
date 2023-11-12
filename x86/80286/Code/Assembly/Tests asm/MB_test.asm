;### Code by Dominic Emond-Belanger
;### Using the NASM Assembler
;
; *physical memory map*
;-----------------------
;-    ROM  (0.5 MB)    -
;-   0x80000-0xFFFFF   -
;-----------------------
;-    RAM  (0.5 MB)    -
;-   0x00000-0x7FFFF   -
;-----------------------
;

CPU 286
BITS 16

TIMES 0x80000-($-$$) DB 0		;Fill bottom half of ROM with zeros.

section .data

	LEDBAR		equ 0xF0

section .text		; Start at 0x8000

ORG 0x0							;Starts at 0x0, but first half of ROM is not used

TOP:							;Physically at 0x80000 in ROM
cli								;disable interrupts

;*** SETUP REGISTERS **********************************
;mov	ax,	0X0
;mov	ds,	ax			;data segment
;mov	es,	ax			;extra segment
;mov	sp,	ax			;Start at 0, will wrap around to FFFE
;mov ax, 0x0040		; First 1k is reserved for interupt vector table.
;mov	ss,	ax			;stack segment
;*** /SETUP REGISTERS *********************************

START:
mov al, 0x0F
out LEDBAR, al

mov al, 0xF0
out LEDBAR, al

JMP START

NOP
NOP
NOP
NOP

hlt
hlt
hlt

;-----------------------------------------------------------------------

TIMES 0xFFFF0-($-$$) NOP	;Fill ROM with NOPs up to startup address
							;This will get to 0xFFFF0

RESET:							;0xFFFF0	*Processor starts reading here
	JMP 0x8000:0x0						;EA	00 00 00 80		Jump to TOP: label

TIMES 0x100000-($-$$) DB 1	;Fill the rest of ROM with bytes of 0x01