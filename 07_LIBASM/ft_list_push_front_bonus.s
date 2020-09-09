extern		_malloc

section		.text
global		_ft_list_push_front

_ft_list_push_front:
	
	push	rdi
	xor		rax, rax			;initialize

malloc_space:
	
	push	rsi					;restore rsi
	push	rdi					;restore rdi
	mov		rdi, 16				;size to malloc
	call	_malloc				;call malloc
	
put_data:

	pop		rdi
	pop		rsi
	cmp		rax, 0				;if rax is 0, ERROR
	je		error
	mov		[rax], rsi			;copy data
	mov		rbx, [rdi]		
	mov		[rax + 8], rbx		;next is rdi

error:
	
	pop		rdi
	mov		[rdi], rax			;first node is rax
	ret
