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

TIMES 0x80000-($-$$) DB 0xFF					;Fill bottom half of ROM with zeros.

section .data

; ****** Definitions *****************************

; **** Define the verbose output level for debuging ****

; Level definisions :
; 0x0 = No verbose output
; 0x1 = Information only
; 0x2 = Information + Warning
; 0x3 = Information + Warning + debug

	%define		Verbose_lvl		0x3			; Set verbose message level

; **** Define OnBoard devices ****

	%define		PPI1_PRESENT
	%define		PPI2_PRESENT
	%define		VIA1_PRESENT
	%define		VFD_PRESENT	
	%define		NANO_PRESENT

; ****** DEVICES ADDRESS ***************************

	LEDBAR			equ		0xDE			; Onboard LED Bargraph address

	DIP_SWITCH		equ		0xDC			; Onboard DIP Switches address
	
	PPI1_PORTA		equ		0xE0			; Onboard PPI 1 Port A address
	PPI1_PORTB		equ		0xE2			; Onboard PPI 1 Port B address
	PPI1_PORTC		equ		0xE4			; Onboard PPI 1 Port C address
	PPI1_CTL		equ		0xE6			; Onboard PPI 1 Control Port address

	PPI2_PORTA		equ		0xE8			; Onboard PPI 2 Port A address
	PPI2_PORTB		equ		0xEC			; Onboard PPI 2 Port B address
	PPI2_PORTC		equ		0xEE			; Onboard PPI 2 Port C address
	PPI2_CTL		equ		0xF0			; Onboard PPI 2 Control Port address

	VIA1_PORTA		equ		0xF2			; Onboard VIA 1 Port A address
	VIA1_PORTB		equ		0xF4			; Onboard VIA 1 Port B address
	VIA1_DDRA		equ		0xF6			; Configure VIA 1 Port A
	VIA1_DDRB		equ		0xF8			; Configure VIA 1 Port B
	VIA1_IER		equ		0xFA			; Configure VIA 1 interrupt information

; ****** VARIABLES **********************************

	; PPI Configuration
	PPI_CTL_PA_IN	equ	0b10010000			; 0x90
	PPI_CTL_PA_OUT	equ	0b10000000			; 0x80

	; VFD Configuration
	VFD_RS	equ 0b00000001
	VFD_RW	equ 0b00000010
	VFD_RD	equ 0b00000100

	; SPI Configuration
	SPI_MISO		equ		0b00000001
	SPI_MOSI		equ		0b00000010
	SPI_CLK			equ		0b00000100

	SPI_CS1			equ		0b10000000			; 8-digit 7-segment display						Arduino Nano serial output
	SPI_CS2			equ		0b01000000			; N/A											N/A
	SPI_CS3			equ		0b00100000			; N/A											N/A
	SPI_CS4			equ		0b00010000			; N/A											N/A
	SPI_CS5			equ		0b00001000			; N/A											N/A

global _start

section .text start=0x80000					; Start at 0x80000

_start:										; Physically at 0x80000 in ROM

;*** SETUP REGISTERS **********************************
mov	ax,	0x0
mov	ds,	ax									; data segment
mov	es,	ax									; extra segment
mov	sp,	ax									; Start at 0, will wrap around to FFFE
mov ax, 0x0040								; First 1k is reserved for interupt vector table.
mov	ss,	ax									; stack segment
;*** /SETUP REGISTERS *********************************

cli											;disable interrupts

call	_vfd_init

call	_test_msg

mov		bx, str_booting
call	_print_msg_vfd

hlt											; Halt the computer
hlt											; Halt the computer
hlt											; Halt the computer

; ****** Functions *********************************

section .text

_test_msg:
	mov al, 'H'
	call _print_char
	mov al, 'E'
	call _print_char
	mov al, 'L'
	call _print_char
	mov al, 'L'
	call _print_char
	mov al, 'O'
	call _print_char
	mov al, '!'
	call _print_char
	ret

_ppi_ctl_set:
	push	dx								; Save DX to the stack
	mov		dx,	PPI1_CTL					; Send the device address to DX
	out		dx,	al							; Output AL to the device address

	pop		dx								; Restore DX from the stack
	ret										; Return to caller

_vfd_init:
	push	dx								; Save DX to the stack
	MOV		DX, PPI1_CTL
	MOV		AL,	0b10000000					;to make all ports output
	OUT		DX,	AL 

	mov		al, 0x0C						; Clear the vfd
	call	_vfd_cmd_wr
	pop		dx								; Restore DX from the stack
	ret

_vfd_cmd_wr:
	push	dx
	mov		dx,	PPI1_PORTA
	out		dx,	al
	mov		dx,	PPI1_PORTB
	mov		al, VFD_RW
	out		dx,	al
	nop
	nop
	mov		al, 0x0
	out		dx, al
	pop		dx
	ret										; Return to caller

_print_msg_vfd:
	push	bx 								; Save BX 
	push	cx 								; and CX onto the sack
	mov		cx, bx 							; Save contents of BX for later use
	
	.loop:
		mov		al, es:[bx]					; Read byte from [DS:BX]
		or		al, al 						; Did we encounter a NUL character?
		jz		.return 					; If so, return to the caller
		call	_print_char 				; call our character print routine
		inc		bx 							; Increment the index
		jmp		.loop 						; And loop back
	
	.return: 
		sub		bx, cx 						; Calculate our number of characters printed
		mov		ax, bx 						; And load the result into AX
		pop		cx 							; Restore CX
		pop		bx 							; and BX from the stack
		ret									; Return to caller

_print_char:
	push	dx
	push	ax

	mov		dx,		PPI1_PORTA				; Get A port address
	out		dx,		al						; Write data (e.g. char) to port A
	mov		al,		(VFD_RS | VFD_RW)		; RS=1, RW=1, RD=0
	mov		dx,		PPI1_PORTB				; Get B port address
	out		dx,		al						; Write to port B - enable high
	nop										; wait for high-to-low pulse to be wide enough
	nop
	mov		al,		VFD_RS					; RS=1, RW=0, RD=0
	out		dx,		al						; Write to port B - enable low

	pop		ax								; Restore AX from the satck
	pop		dx								; Restore DX from the satck
	ret										; Return to caller

_ledbar_out:
	push	dx 								; Save DX
	mov		dx, LEDBAR 						; Send LEDBAR address to DX
	out		dx, al 							; Output AL value to to LEDBAR device
	pop		dx 								; Restore DX from the stack
	ret										; Return to caller

;section .rodata start=0x30000

; ****** STRINGS ************************************

	str_booting							db	"System Booting...", 0x0
	str_loading							db	"Loading...", 0x0
	str_update_bios						db	"BIOS update in progress...", 0x0
	str_update_bios_completed			db	"BIOS update completed!", 0x0

;************************************************************************

TIMES 0xFFFF0-($-$$) db 0xff				; Fill ROM with 0xFF up to startup address
											; This will get to 0xFFFF0
section .bootvector
	_reset:									; 0xFFFF0	*Processor starts reading here
		JMP 0x8000:0x0						; EA	00 00 00 80		Jump to TOP: label

TIMES 0x10-($-$$) DB 0xff					; Fill the rest of ROM with bytes of 0xFF