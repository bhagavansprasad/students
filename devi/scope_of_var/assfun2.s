	.file	"assfun2.c"
	.section	.rodata
.LC1:
	.string	"I am function2"
	.align 4
.LC2:
	.string	"the values from fun1 int s=%d and double j=%lf\n"
	.align 4
.LC3:
	.string	"from fun1 the addr of s is %u and j is %u\n"
	.align 4
.LC4:
	.string	" the addr of ch is %u and f is %u\n"
	.text
	.globl	fun2
	.type	fun2, @function
fun2:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	12(%ebp), %eax
	movl	%eax, -32(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, -28(%ebp)
	movb	$65, -17(%ebp)
	fldl	.LC0
	fstpl	-16(%ebp)
	movl	$.LC1, (%esp)
	call	puts
	fldl	-32(%ebp)
	movl	8(%ebp), %eax
	fstpl	8(%esp)
	movl	%eax, 4(%esp)
	movl	$.LC2, (%esp)
	call	printf
	leal	-32(%ebp), %eax
	movl	%eax, 8(%esp)
	leal	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC3, (%esp)
	call	printf
	leal	-16(%ebp), %eax
	movl	%eax, 8(%esp)
	leal	-17(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC4, (%esp)
	call	printf
	fldl	-16(%ebp)
	movzbl	-17(%ebp), %eax
	movsbl	%al, %eax
	fstpl	4(%esp)
	movl	%eax, (%esp)
	call	fun3
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	fun2, .-fun2
	.section	.rodata
	.align 8
.LC0:
	.long	0
	.long	1081901056
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
