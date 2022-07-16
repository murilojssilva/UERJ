	.file	"apaga.c"
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
	subq	$16, %rsp
	movb	$32, -2(%rbp)
	movl	$0, -8(%rbp)
	jmp	.L2
.L11:
	cmpb	$47, -2(%rbp)
	jne	.L3
	cmpb	$47, -1(%rbp)
	jne	.L3
	movl	$1, -8(%rbp)
.L3:
	cmpb	$47, -2(%rbp)
	jne	.L4
	cmpb	$42, -1(%rbp)
	jne	.L4
	movl	$1, -8(%rbp)
.L4:
	cmpl	$1, -8(%rbp)
	jne	.L5
	cmpb	$42, -2(%rbp)
	jne	.L6
	cmpb	$47, -1(%rbp)
	je	.L7
.L6:
	cmpb	$10, -1(%rbp)
	jne	.L8
.L7:
	movl	$0, -8(%rbp)
	jmp	.L10
.L8:
	movb	$8, -1(%rbp)
	jmp	.L10
.L5:
	movsbl	-1(%rbp), %eax
	movl	%eax, %edi
	call	putchar
.L10:
	movzbl	-1(%rbp), %eax
	movb	%al, -2(%rbp)
.L2:
	call	getchar
	movb	%al, -1(%rbp)
	cmpb	$-1, -1(%rbp)
	jne	.L11
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
