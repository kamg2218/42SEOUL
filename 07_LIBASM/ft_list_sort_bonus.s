section		.text
global		_ft_list_sort

_ft_list_sort:
	
	cmp		rdi, 0				;check rdi
	je		end
	cmp		rsi, 0				;check rsi
	je		end
	xor		rax, rax			;initialize
	mov		rbx, [rdi]			;check *rdi
	cmp		rbx, 0				;*rdi == 0
	je		end
	mov		rcx, [rbx + 8]		;(*rdi)->next == 0
	cmp		rcx, 0
	je		end
	mov		r8, rsi
	jmp		compare

increase_list:

	mov		rbx, [rbx + 8]		;*rdi = (*rdi)->next
	cmp		rbx, 0				;if address is zero,
	je		end					;finish
	mov		rcx, [rbx + 8]		;(*rdi)->next = (*rdi)->next->next
	cmp		rcx, 0				;if address is zero,
	je		end					;finish
	jmp		compare				;compare data

increase_cmp:

	mov		rcx, [rcx + 8]		;move (*rdi)->next->next
	cmp		rcx, 0				;if address is zero,
	je		increase_list		;move *rdi node

compare:

	cmp		QWORD[rbx], 0
	je		increase_list
	cmp		QWORD[rcx], 0
	je		change_list
	push	rbx					;restore *rdi
	push	rcx					;restore (*rdi)->next
	push	r8					;cmp function
	mov		rdi, [rbx]			;*rdi data
	mov		rsi, [rcx]			;(*rdi)->next data
	call	r8					;call cmp function
	pop		r8
	pop		rcx
	pop		rbx
	cmp		rax, 1				;if *rdi data is bigger,
	jge		change_list			;change data
	jmp		increase_cmp		;repeat

change_list:

	mov		r9, [rbx]			;*rdi data
	mov		r10, [rcx]			;(*rdi)->next data
	mov		[rbx], r10			;change each other
	mov		[rcx], r9
	jmp		increase_cmp		;repeat comparing data

end:

	ret
