	.file	"point.c"
	.text
	.section	.rodata
	.align 8
.LC0:
	.string	"\344\275\277\347\224\250\346\225\260\347\273\204\346\214\207\351\222\210\347\232\204\346\226\271\345\274\217\350\256\277\351\227\256\344\272\214\347\273\264\346\225\260\347\273\204arr"
.LC1:
	.string	"arr[%d][%d] = %d\t\n"
	.align 8
.LC2:
	.string	"\n\344\275\277\347\224\250\346\214\207\351\222\210\346\225\260\347\273\204\346\226\271\345\274\217\350\256\277\351\227\256\344\272\214\347\273\264\346\225\260\347\273\204arr:"
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
	subq	$160, %rsp
	movl	%edi, -148(%rbp)
	movq	%rsi, -160(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$1, -80(%rbp)
	movl	$2, -76(%rbp)
	movl	$3, -72(%rbp)
	movl	$4, -68(%rbp)
	movl	$5, -64(%rbp)
	movl	$6, -60(%rbp)
	movl	$7, -56(%rbp)
	movl	$8, -52(%rbp)
	movl	$9, -48(%rbp)
	movl	$10, -44(%rbp)
	movl	$11, -40(%rbp)
	movl	$12, -36(%rbp)
	movl	$13, -32(%rbp)
	movl	$14, -28(%rbp)
	movl	$15, -24(%rbp)
	movl	$16, -20(%rbp)
	leaq	-80(%rbp), %rax
	movq	%rax, -120(%rbp)
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	movl	$0, -132(%rbp)
	jmp	.L2
.L5:
	movl	$0, -128(%rbp)
	jmp	.L3
.L4:
	movl	-132(%rbp), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rdx
	movq	-120(%rbp), %rax
	addq	%rax, %rdx
	movl	-128(%rbp), %eax
	cltq
	salq	$2, %rax
	addq	%rdx, %rax
	movl	(%rax), %ecx
	movl	-128(%rbp), %edx
	movl	-132(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -128(%rbp)
.L3:
	cmpl	$3, -128(%rbp)
	jle	.L4
	movl	$10, %edi
	call	putchar@PLT
	addl	$1, -132(%rbp)
.L2:
	cmpl	$3, -132(%rbp)
	jle	.L5
	leaq	.LC2(%rip), %rdi
	call	puts@PLT
	movl	$0, -132(%rbp)
	jmp	.L6
.L7:
	leaq	-80(%rbp), %rax
	movl	-132(%rbp), %edx
	movslq	%edx, %rdx
	salq	$4, %rdx
	addq	%rax, %rdx
	movl	-132(%rbp), %eax
	cltq
	movq	%rdx, -112(%rbp,%rax,8)
	addl	$1, -132(%rbp)
.L6:
	cmpl	$3, -132(%rbp)
	jle	.L7
	movl	$0, -124(%rbp)
	jmp	.L8
.L11:
	movl	$0, -128(%rbp)
	jmp	.L9
.L10:
	movl	-124(%rbp), %eax
	cltq
	movq	-112(%rbp,%rax,8), %rax
	movl	-128(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rdx, %rax
	movl	(%rax), %ecx
	movl	-128(%rbp), %edx
	movl	-132(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -128(%rbp)
.L9:
	cmpl	$3, -128(%rbp)
	jle	.L10
	movl	$10, %edi
	call	putchar@PLT
	addl	$1, -124(%rbp)
.L8:
	cmpl	$3, -124(%rbp)
	jle	.L11
	movl	$0, %eax
	movq	-8(%rbp), %rsi
	xorq	%fs:40, %rsi
	je	.L13
	call	__stack_chk_fail@PLT
.L13:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
