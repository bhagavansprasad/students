	.file	"1.c"
	.section	.rodata
.LC0:
	.string	"%d"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$48, %esp
	movl	$2, 44(%esp)
	movl	44(%esp), %eax
	movl	$0, 28(%esp)
	movl	%eax, %edx
	sarl	$31, %edx
	idivl	28(%esp)
	movl	%eax, 40(%esp)
	movl	$.LC0, %eax
	movl	40(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.4.3-4ubuntu5.1) 4.4.3"
	.section	.note.GNU-stack,"",@progbits
