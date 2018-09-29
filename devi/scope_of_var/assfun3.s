	.file	"assfun3.c"
	.section	.rodata
.LC0:
	.string	"I am function3"
	.align 4
.LC1:
	.string	"the values from fun2 c=%c\tg=%lf\n"
	.align 4
.LC2:
	.string	"the addr of char c is %u and double d is %u\n"
	.align 4
.LC3:
	.string	"from fun3 the val of str is %s and adr is %u"
	.text
	.globl	fun3
	.type	fun3, @function
fun3:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%ebx
	subl	$144, %esp
	.cfi_offset 7, -12
	.cfi_offset 3, -16
	movl	8(%ebp), %eax
	movb	%al, -124(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, -136(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, -132(%ebp)
	movl	%gs:20, %eax
	movl	%eax, -12(%ebp)
	xorl	%eax, %eax
	movl	$1634891073, -112(%ebp)
	movl	$0, -108(%ebp)
	leal	-104(%ebp), %ebx
	movl	$0, %eax
	movl	$23, %edx
	movl	%ebx, %edi
	movl	%edx, %ecx
	rep stosl
	movl	$.LC0, (%esp)
	call	puts
	fldl	-136(%ebp)
	movzbl	-124(%ebp), %eax
	movsbl	%al, %eax
	fstpl	8(%esp)
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	printf
	leal	-136(%ebp), %eax
	movl	%eax, 8(%esp)
	leal	-124(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC2, (%esp)
	call	printf
	leal	-112(%ebp), %eax
	movl	%eax, 8(%esp)
	leal	-112(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC3, (%esp)
	call	printf
	movl	-12(%ebp), %eax
	xorl	%gs:20, %eax
	je	.L2
	call	__stack_chk_fail
.L2:
	addl	$144, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	fun3, .-fun3
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
