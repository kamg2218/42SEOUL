section		.text
global		_ft_list_size

_ft_list_size:

	xor		rax, rax			;initialize

while:

	cmp		rdi, 0				;check rdi
	je		end
	inc		rax					;increase rax
	mov		rdi, [rdi + 8]		;move next node
	jmp		while				;repeat

end:

	ret
