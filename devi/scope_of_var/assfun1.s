	.file	"assfun1.c"
	.section	.rodata
.LC1:
	.string	"I am function1"
	.align 4
.LC2:
	.string	"the values from main is x=%d and y=%d\n"
	.align 4
.LC3:
	.string	"the addr of x is %u and y is %u\n"
	.align 4
.LC4:
	.string	"the addr of e is %u and d is %u\n"
	.text
	.globl	fun1
	.type	fun1, @function
fun1:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$50, -16(%ebp)
	movl	.LC0, %eax
	movl	%eax, -12(%ebp)
	movl	$.LC1, (%esp)
	call	puts
	movl	12(%ebp), %edx
	movl	8(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$.LC2, (%esp)
	call	printf
	leal	12(%ebp), %eax
	movl	%eax, 8(%esp)
	leal	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC3, (%esp)
	call	printf
	leal	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	leal	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC4, (%esp)
	call	printf
	flds	-12(%ebp)
	movl	-16(%ebp), %eax
	fstpl	4(%esp)
	movl	%eax, (%esp)
	call	fun2
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	fun1, .-fun1
	.section	.rodata
	.align 4
.LC0:
	.long	1110704128
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
