section		.text
global		_ft_write

_ft_write:
	
	mov		rax, 0x2000004		;write system call write
	mov		rbx, rdi			;fd
	mov		rcx, rsi			;string
	syscall
	ret
