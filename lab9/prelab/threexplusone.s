	;; Christian Kinzer
	;; cfk5ax
	;; 11/19/18
	;; 9:30 AM
	;; threexplusone.s
	;; optimization: used shr instead of idiv to divide by 2
	;; optimization: used jnc to evaluate remainder

	global threexplusone
	section .text

threexplusone:
	push rbp 		; save base
	mov rbp, rsp		; reset base
	xor rax, rax		; 0 out rax
	cmp rdi, 1		; cmp 3x+1 with 1 (base case)
	je end			; jump to end if done
	jmp recursion		; otherwise continue

recursion:
	shr rdi, 1		; testing to see if x is even
	jnc even		; go to even if even, continue if odd
	shl rdi, 1		; restore param
	imul rdi, 3		; 3x
	add rdi, 1		; 3x+1
	push rdi		; push the param
	call threexplusone	; recurse
	add rax, 1		; count++
	jmp end			; finish

even:
	shr rdi, 1		; x/2
	push rdi		; push param
	call threexplusone	; recurse
	add rax, 1		; count++
	jmp end			; finish

end:
	mov rsp, rbp		; deallocate local vars
	pop rbp			; restore base
	ret			; return count
