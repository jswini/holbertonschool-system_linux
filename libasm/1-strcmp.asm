bits 64

	global asm_strcmp

	section .text

asm_strcmp:

	push rdi 		;save contents of rdi
	push rsi		;save contents of rsi
	push rcx		;save contents of rcx
	
_cmp_char_loop:
	cmp byte [rdi], 0		;compare value pointed to from RDI to 0
	jz _end					;if zero end function
	mov rcx, [rsi]			;put dereferenced rsi into rcx
	cmp [rdi], rcx			;compare values of pointers to each other
	jne _end				;exit function if not equal
	inc rdi					;increment to next char
	inc rsi					;increment to next char
	je _cmp_char_loop		;go back to top of loop to compare the next chars

_end:
	xor al, al
	mov al, byte [rdi]			;put return value in rax
	sub al, cl 			;rax = rax - rcx
	pop rcx
	pop rsi
	pop rdi
	ret
