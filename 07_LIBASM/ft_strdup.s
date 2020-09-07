extern		_malloc

section		.text
global		_ft_strdup

_ft_strdup:
	
	cmp		rdi, 0					;if rdi is null, return 0
	jz		error
	xor		rbx, rbx				;initialize

while:
	
	cmp		byte[rdi + rbx], 0		;check rdi array
	jz		allocate
	inc		rbx						;increase number
	jmp		while					;repeat

allocate:

	inc		rbx					
	push	rdi
	mov		rdi, rbx				;size to malloc
	call	_malloc					;call malloc
	pop		rdi
	cmp		rax, 0					;if return value is zero, ERROR
	jz		error
	xor		rcx, rcx

put:

	mov		dl, byte[rdi + rcx]		;move data rdi to rax
	mov		byte[rax + rcx], dl
	cmp		dl, 0					;if dl is zero, it means last
	je		end
	inc		rcx						;increase number
	jmp		put						;repeat

error:

	xor		rax, rax				;if it's error, return zero

end:
	
	ret
