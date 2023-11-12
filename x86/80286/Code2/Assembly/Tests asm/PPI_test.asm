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

	PPI1_PORTA	equ 0xE0
	PPI1_PORTB	equ 0xE2
	PPI1_PORTC	equ 0xE4
	PPI1_CTL	equ 0xE6

	;PPI1 Configuration

	PPI1_CTL_PA_IN		equ	0b10010000	;0x90
	PPI1_CTL_PA_OUT		equ	0b10000000	;0x80

section .text		; Start at 0x8000

ORG 0x0							;Starts at 0x0, but first half of ROM is not used

TOP:							;Physically at 0x80000 in ROM
cli								;disable interrupts

;*** SETUP REGISTERS **********************************
mov	ax,	0X0
mov	ds,	ax			;data segment
mov	es,	ax			;extra segment
mov	sp,	ax			;Start at 0, will wrap around to FFFE
mov ax, 0x0040		; First 1k is reserved for interupt vector table.
mov	ss,	ax			;stack segment
;*** /SETUP REGISTERS *********************************

call	lcd_init
call	print_msg

hlt
hlt
hlt



print_msg:
	mov al, 'H'
	call lcd_data_wr
	mov al, 'E'
	call lcd_data_wr
	mov al, 'L'
	call lcd_data_wr
	mov al, 'L'
	call lcd_data_wr
	mov al, 'O'
	call lcd_data_wr
	mov al, '!'
	call lcd_data_wr

lcd_init:
	mov al, 0x0C	; Clear the LCD
	call lcd_cmd_wr

lcd_cmd_wr:
	push dx
	mov dx,	PPI1_PORTA
	out dx,	al
	mov dx,	PPI1_PORTB
	mov al, E
	out dx,	al
	nop
	nop
	mov al, 0x0
	out dx, al
	pop dx
	ret

lcd_data_wr:
	

;-----------------------------------------------------------------------

TIMES 0xFFFF0-($-$$) NOP	;Fill ROM with NOPs up to startup address
							;This will get to 0xFFFF0

RESET:							;0xFFFF0	*Processor starts reading here
	JMP 0x8000:0x0						;EA	00 00 00 80		Jump to TOP: label

TIMES 0x100000-($-$$) DB 1	;Fill the rest of ROM with bytes of 0x01