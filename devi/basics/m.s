	.file	"m.c"
	.globl	n
	.data
	.align 4
	.type	n, @object
	.size	n, 4
n:
	.long	10
	.section	.rodata
.LC0:
	.string	"temp--->%d\n"
.LC1:
	.string	"i--->%d\n"
.LC2:
	.string	"n--->%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	movl	$1, 28(%esp)
	jmp	.L2
.L3:
	movl	$100, 4(%esp)
	movl	$.LC0, (%esp)
	call	printf
	movl	28(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	printf
	movl	n, %eax
	movl	%eax, 4(%esp)
	movl	$.LC2, (%esp)
	call	printf
	addl	$1, 28(%esp)
.L2:
	cmpl	$5, 28(%esp)
	jle	.L3
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
