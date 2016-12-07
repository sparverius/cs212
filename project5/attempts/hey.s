	.file	"hey.c"
	.comm	c_count,4,4
	.comm	m_count,4,4
	.comm	l_count,4,4
	.comm	w_count,4,4
	.comm	buffer,1,1
	.comm	word,4,4
	.section	.rodata
.LC0:
	.string	"%d\n"
.LC1:
	.string	"wrong"
.LC2:
	.string	"%s"
.LC3:
	.string	"cmwl"
.LC4:
	.string	"%2d %2d %2d %s\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movl	$0, word(%rip)
	movl	word(%rip), %eax
	movl	%eax, c_count(%rip)
	movl	c_count(%rip), %eax
	movl	%eax, m_count(%rip)
	movl	m_count(%rip), %eax
	movl	%eax, l_count(%rip)
	movl	-20(%rbp), %eax
	cltq
	salq	$3, %rax
	leaq	-8(%rax), %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	getfrom
	cmpl	$2, -20(%rbp)
	jle	.L2
	jmp	.L3
.L10:
	movl	-4(%rbp), %eax
	cmpl	$108, %eax
	je	.L5
	cmpl	$108, %eax
	jg	.L6
	cmpl	$99, %eax
	je	.L7
	jmp	.L4
.L6:
	cmpl	$109, %eax
	je	.L8
	cmpl	$119, %eax
	je	.L9
	jmp	.L4
.L7:
	movl	c_count(%rip), %eax
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	jmp	.L3
.L8:
	movl	m_count(%rip), %eax
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	jmp	.L3
.L5:
	movl	l_count(%rip), %eax
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	jmp	.L3
.L9:
	movl	w_count(%rip), %eax
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	jmp	.L3
.L4:
	movl	$.LC1, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
.L3:
	movq	-32(%rbp), %rcx
	movl	-20(%rbp), %eax
	movl	$.LC3, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	getopt
	movl	%eax, -4(%rbp)
	cmpl	$-1, -4(%rbp)
	jne	.L10
	jmp	.L11
.L2:
	movq	-32(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rsi
	movl	c_count(%rip), %ecx
	movl	w_count(%rip), %edx
	movl	l_count(%rip), %eax
	movq	%rsi, %r8
	movl	%eax, %esi
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
.L11:
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.globl	getfrom
	.type	getfrom, @function
getfrom:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	open
	jmp	.L14
.L18:
	movzbl	buffer(%rip), %eax
	testb	%al, %al
	js	.L15
	movl	c_count(%rip), %eax
	addl	$1, %eax
	movl	%eax, c_count(%rip)
	movl	m_count(%rip), %eax
	addl	$1, %eax
	movl	%eax, m_count(%rip)
	movzbl	buffer(%rip), %eax
	cmpb	$10, %al
	jne	.L15
	movl	l_count(%rip), %eax
	addl	$1, %eax
	movl	%eax, l_count(%rip)
.L15:
	movzbl	buffer(%rip), %eax
	cmpb	$32, %al
	je	.L16
	movzbl	buffer(%rip), %eax
	cmpb	$10, %al
	jne	.L17
.L16:
	movl	$0, word(%rip)
	jmp	.L14
.L17:
	movl	word(%rip), %eax
	testl	%eax, %eax
	jne	.L14
	movl	w_count(%rip), %eax
	addl	$1, %eax
	movl	%eax, w_count(%rip)
	movl	$1, word(%rip)
.L14:
	movl	$1, %edx
	movl	$buffer, %esi
	movl	$3, %edi
	call	read
	testl	%eax, %eax
	jne	.L18
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	getfrom, .-getfrom
	.globl	getword
	.type	getword, @function
getword:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, %eax
	movb	%al, -4(%rbp)
	cmpb	$32, -4(%rbp)
	jne	.L20
	movl	$0, word(%rip)
	jmp	.L22
.L20:
	cmpb	$0, -4(%rbp)
	jne	.L22
	movl	w_count(%rip), %eax
	addl	$1, %eax
	movl	%eax, w_count(%rip)
	movl	$1, word(%rip)
.L22:
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	getword, .-getword
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.2) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
