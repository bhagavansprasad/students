	.file	"2.7.7.c"
.globl a
	.data
	.align 4
	.type	a, @object
	.size	a, 4
a:
	.long	10
	.comm	b,4,4
	.section	.rodata
.LC0:
	.string	"-->a: %d\n"
.LC1:
	.string	"-->b: %d\n"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$16, %esp
	movl	a, %eax
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	printf
	movl	b, %eax
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	printf
	call	my_function1
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.4.7-1ubuntu2) 4.4.7"
	.section	.note.GNU-stack,"",@progbits
