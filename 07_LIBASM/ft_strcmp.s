section		.text
global		_ft_strcmp

_ft_strcmp:

	cmp		rdi, 0						;check rdi
	je		dst_null
	cmp		rsi, 0						;check rsi
	je		src_null
	xor		rbx, rbx					;initialize

while:

	mov		cl, byte[rdi + rbx]			;copy rdi
	mov		dl, byte[rsi + rbx]			;copy rsi
	sub		cl, dl						;substract dl
	cmp		cl, 0						
	jl		minus						;cl is minus
	jg		plus						;cl is plus
	cmp		dl, 0						;if dl is zero, it means last 
	jz		same					
	inc		rbx							;increase count
	jmp		while						;repeat

dst_null:

	cmp		rsi, 0						;if rsi is null, return 0
	je		same
	jmp		minus						;else return -1

src_null:

	cmp		rdi, 0						;if rdi is null, return 0
	je		same
	jmp		plus						;else return 1

plus:
	
	mov		rax, 1						;return 1
	jmp		end

minus:

	mov		rax, -1						;return -1
	jmp		end

same:
	
	mov		rax, 0						;return 0

end:

	ret
