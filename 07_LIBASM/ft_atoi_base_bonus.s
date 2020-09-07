section		.text
global		_ft_atoi_base

_ft_atoi_base:

	xor		r8, r8					;initialize
	xor		r9, r9					;initialize
	xor		r10, r10				;initialize
	xor		r11, r11				;initialize
	mov		rax, 1					;plus or minus
	jmp		count_base

increase_base:

	xor		rbx, rbx				;initialize
	inc		r11						;increase number

count_base:

	cmp		byte[rsi + r11], 0		;check last
	jz		space
	cmp		byte[rsi + r11], 48		;if under 0, ERROR
	jl		error
	cmp		byte[rsi + r11], 57		;if under 9, check alphabet
	jg		second_check_base
	jmp		double_check

second_check_base:

	cmp		byte[rsi + r11], 65		;if under A, ERROR
	jl		error
	cmp		byte[rsi + r11], 90		;if under Z, double check base
	jl		double_check
	cmp		byte[rsi + r11], 97		;if under a, ERROR
	jl		error
	cmp		byte[rsi + r11], 122	;if upper z, ERROR
	jg		error
	jmp		double_check			;double check base

increase_double:
	
	inc		rbx

double_check:

	cmp		r11, rbx				;check same number
	je		increase_double			;except same number, check the base
	cmp		byte[rsi + rbx], 0		
	je		increase_base
	mov		dl, byte[rsi + r11]		;if two characters are same, ERROR
	cmp		byte[rsi + rbx], dl
	je		error
	jmp		increase_double			;increase base position

increase:

	inc		r8

space:

	cmp		byte[rdi + r8], 32		;check space
	je		increase
	cmp		byte[rdi + r8], 9		;if it's not a space, pass
	jl		plus
	cmp		byte[rdi + r8], 13		;if it's not a space, pass
	jg		plus
	jmp		increase				;increase r8

plus:

	cmp		byte[rdi + r8], 45		;if -
	je		minus
	cmp		byte[rdi + r8], 43		;if not +, pass
	jne		set_zero				
	inc		r8						;increase r8
	jmp		plus					;repeat plus

minus:

	mov		rdx, -1					;multiply -1
	mul		rdx
	inc		r8
	jmp		plus					;repeat plus

set_zero:

	mov		r10, rax				;final sign
	xor		rax, rax				;prepare to calculate number

zero_base:

	xor		r9, r9					;space to restore rsi position

check_base:

	mov		dl, byte[rsi + r9]
	cmp		byte[rdi + r8], dl		;compare number with base
	je		add_num					;if same, calculate it
	inc		r9						;else increase r9(base count)
	cmp		byte[rsi + r9], 0		;check null
	je		end						;if null, jump to end
	jmp		check_base				;repeat check_base

add_num:

	mul		r11						;multiply length of base
	add		rax, r9					;add base position
	inc		r8						;increase r8
	cmp		byte[rdi + r8], 0		;check null
	jne		zero_base				;if not null, repeat zero_base
	
end:

	mul		r10						;multiply sign
	ret

error:

	mov		rax, 0					;if error happens, return 0
	ret
