extern		_free

section		.text
global		_ft_list_remove_if

_ft_list_remove_if:

	push	rdi						;restore first address
	mov		rbx, [rdi]				;copy first node
	mov		r9, [rdi]				;copy first node
	xor		r8, r8					;initialize
	cmp		rdi, 0					;if first node is null,
	je		error					;finish
	cmp		rdx, 0					;if cmp address is null,
	je		error					;finish
	cmp		rcx, 0					;if free address is null,
	je		error					;finish
	jmp		compare_list			;compare start!

compare_null:

	xor		rdi, rsi				;rdi is null, if rdi and rsi are same,
	mov		rax, rdi				;rdi is zero
	jmp		compare_list_second		;compare rax

move_next:

	mov		rbx, [rbx + 8]			;present node = present node ->next

compare_list:

	cmp		rbx, 0					;if rbx is zero,
	je		end						;end
	push	rbx						;restore present node
	push	rsi						;restore data
	push	rdx						;restore cmp function
	push	rcx						;restore free function
	push	r8						;restore previous node
	push	r9						;restore first node
	mov		rdi, [rbx]				;present node data
	cmp		rdi, 0					;if data is null,
	je		compare_null			;jump to compare_null
	call	rdx						;else, call cmp function
	
compare_list_second:

	pop		r9
	pop		r8
	pop		rcx
	pop		rdx
	pop		rsi
	pop		rbx
	cmp		rax, 0					;if result is 0,
	je		check_tmp				;check first node
	mov		r8, rbx					;else, change previous node
	jmp		move_next				;repeat comparing

null_tmp:

	mov		r9, [rbx + 8]			;first node is present node -> next
	jmp		remove_data

check_tmp:
	
	cmp		r8, 0					;if previous node is null,
	je		null_tmp				;jump null_tmp
	mov		r10, [rbx + 8]			;else, previous node -> next is
	mov		[r8 + 8], r10			;present node -> next

remove_data:

	mov		rdi, [rbx]				;move present node -> data
	cmp		rdi, 0					;if present data is null,
	je		remove_null				;jump to remove_null
	push	rsi						;restore data
	push	rdx						;restore cmp address
	push	r8						;restore previous node
	push	r9						;restore first node
	push	rcx						;restore free address
	push	rbx						;restore present node
	call	rcx						;call free

remove_list:

	pop		rbx
	pop		rcx
	push	rcx
	mov		rdi, rbx				;move present node
	call	rcx						;call free
	pop		rcx
	pop		r9
	pop		r8
	pop		rdx
	pop		rsi
	cmp		r8, 0					;if previous node is null,
	je		first_null				;jump first_null
	mov		rbx, [r8 + 8]			;move previous node -> next to present node
	jmp		compare_list			;repeat comparing

first_null:

	mov		rbx, r9					;move first node to present node
	jmp		compare_list			;repeat comparing

remove_null:

	push	r9
	mov		rdi, rbx				;move present node to rdi
	call	rcx						;call free
	pop		r9

end:

	pop		rdi
	mov		[rdi], r9				;move first node to rdi address
	ret

error:

	pop		rdi						;remove data
	ret
