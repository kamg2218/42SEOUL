section		.text
global		_ft_strlen

_ft_strlen:
	
	xor		rax, rax	;initialize
	cmp		rdi, 0		;if null,
	je		end			;finish

while:

	cmp		byte[rdi + rax], 0	;check array
	jz		end
	inc		rax					;count number
	jmp		while				;repeat

end:

	ret
