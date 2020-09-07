section		.text
global		_ft_read

_ft_read:
	
	xor		rcx, rcx
	mov		rax, 0x2000003		;write
	mov		rbx, rdi			; fd
	mov		rcx, rsi			; string
	syscall
	ret
