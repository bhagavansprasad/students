	.file	"assmain.c"
	.section	.rodata
.LC0:
	.string	"I am main"
.LC1:
	.string	"values in main a=%d and b=%d\n"
	.align 4
.LC2:
	.string	"the addr of a is %u and b is %u\n"
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
	movl	$10, 24(%esp)
	movl	$20, 28(%esp)
	movl	$.LC0, (%esp)
	call	puts
	movl	28(%esp), %edx
	movl	24(%esp), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	printf
	leal	28(%esp), %eax
	movl	%eax, 8(%esp)
	leal	24(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC2, (%esp)
	call	printf
	movl	28(%esp), %edx
	movl	24(%esp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	fun1
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
