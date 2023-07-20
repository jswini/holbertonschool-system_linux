bits 64
	global asm_strlen

	section .text

					;prologue
asm_strlen:
	
	push rdi 		;save contents of rsi
	push rcx		;save current contents of rcx
	xor rcx, rcx	;set rcx to zero
	
_count_loop:
	cmp byte [rdi], 0 ;
	jz _end			;jump if zero
	inc rcx			;increment value
	inc rdi			;increment
	jmp _count_loop	;jump to top of loop

_end:
	mov rax, rcx
	pop rcx
	pop rdi
	ret
