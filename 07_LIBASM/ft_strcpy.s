section		.text
global		_ft_strcpy

_ft_strcpy:
	
	cmp		rsi, 0		;input check
	je		error
	cmp		rdi, 0		;input check
	je		error
	xor		rbx, rbx	;rsi count

while:
	
	cmp		byte[rsi + rbx], 0		;array check
	je		while_push
	mov		dl, byte[rsi + rbx]
	mov		byte[rdi + rbx], dl		;copy from rsi to rdi
	inc		rbx						;increase count
	jmp		while					;repeat

while_push:

	mov		byte[rdi + rbx], 0		;last value 0

end:

	mov		rax, rdi				;restore return value
	ret

error:
	
	mov		rax, 0
	ret
