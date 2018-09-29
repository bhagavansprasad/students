	.file	"25printaddr.c"
	.globl	idata1
	.data
	.align 4
	.type	idata1, @object
	.size	idata1, 4
idata1:
	.long	1
	.comm	carray1,10,1
	.globl	cname1
	.align 32
	.type	cname1, @object
	.size	cname1, 128
cname1:
	.string	"Aura Networks"
	.zero	114
	.globl	pname1
	.section	.rodata
.LC0:
	.string	"Aura Networks"
	.data
	.align 4
	.type	pname1, @object
	.size	pname1, 4
pname1:
	.long	.LC0
	.comm	idata2,4,4
	.globl	idata3
	.align 4
	.type	idata3, @object
	.size	idata3, 4
idata3:
	.long	3
	.comm	idata4,4,4
	.comm	sh1,2,2
	.globl	sh2
	.align 2
	.type	sh2, @object
	.size	sh2, 2
sh2:
	.value	2
	.globl	iarray1
	.align 32
	.type	iarray1, @object
	.size	iarray1, 40
iarray1:
	.long	1
	.long	2
	.zero	32
	.globl	iarray2
	.align 32
	.type	iarray2, @object
	.size	iarray2, 40
iarray2:
	.long	10
	.long	20
	.zero	32
	.globl	iarray3
	.align 32
	.type	iarray3, @object
	.size	iarray3, 40
iarray3:
	.long	100
	.long	200
	.long	300
	.zero	28
	.comm	sh3,2,2
	.globl	sh4
	.align 2
	.type	sh4, @object
	.size	sh4, 2
sh4:
	.value	4
	.globl	ch1
	.type	ch1, @object
	.size	ch1, 1
ch1:
	.byte	1
	.comm	ch2,1,1
	.globl	sharray3
	.align 2
	.type	sharray3, @object
	.size	sharray3, 20
sharray3:
	.value	5
	.value	6
	.zero	16
	.globl	ch3
	.type	ch3, @object
	.size	ch3, 1
ch3:
	.byte	3
	.section	.rodata
.LC1:
	.string	"ptr=%p \n"
.LC2:
	.string	"&ptr=%p\n"
.LC3:
	.string	"cname1=%p\n"
.LC4:
	.string	"pname1=%p\n"
.LC5:
	.string	"&pname=%p\n"
.LC6:
	.string	"cname2=%p\n"
.LC7:
	.string	"pname2=%p\n"
.LC8:
	.string	"&pname2=%p\n"
.LC9:
	.string	"fun1=%p\n"
.LC10:
	.string	"fun2=%p\n"
.LC11:
	.string	"fun3=%p\n"
.LC12:
	.string	"ptr=%p\n"
.LC13:
	.string	"iarray1=%p\n"
.LC14:
	.string	"iarray2=%p\n"
.LC15:
	.string	"iarray3=%p\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	andl	$-16, %esp
	subl	$160, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	movl	%gs:20, %eax
	movl	%eax, 156(%esp)
	xorl	%eax, %eax
	movl	$2, 24(%esp)
	movl	$1634891073, 28(%esp)
	movl	$1952796192, 32(%esp)
	movl	$1802661751, 36(%esp)
	movl	$115, 40(%esp)
	leal	44(%esp), %ebx
	movl	$0, %eax
	movl	$28, %edx
	movl	%ebx, %edi
	movl	%edx, %ecx
	rep stosl
	movl	$.LC0, 16(%esp)
	movl	$10, (%esp)
	call	malloc
	movl	%eax, 20(%esp)
	movl	20(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	printf
	leal	20(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC2, (%esp)
	call	printf
	movl	$cname1, 4(%esp)
	movl	$.LC3, (%esp)
	call	printf
	movl	pname1, %eax
	movl	%eax, 4(%esp)
	movl	$.LC4, (%esp)
	call	printf
	movl	$pname1, 4(%esp)
	movl	$.LC5, (%esp)
	call	printf
	leal	28(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC6, (%esp)
	call	printf
	movl	16(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC7, (%esp)
	call	printf
	leal	16(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC8, (%esp)
	call	printf
	movl	$fun1, 4(%esp)
	movl	$.LC9, (%esp)
	call	printf
	movl	$fun2, 4(%esp)
	movl	$.LC10, (%esp)
	call	printf
	movl	$fun3, 4(%esp)
	movl	$.LC11, (%esp)
	call	printf
	movl	$10, (%esp)
	call	malloc
	movl	%eax, 20(%esp)
	movl	20(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC12, (%esp)
	call	printf
	movl	$iarray1, 4(%esp)
	movl	$.LC13, (%esp)
	call	printf
	movl	$iarray2, 4(%esp)
	movl	$.LC14, (%esp)
	call	printf
	movl	$iarray3, 4(%esp)
	movl	$.LC15, (%esp)
	call	printf
	movl	156(%esp), %esi
	xorl	%gs:20, %esi
	je	.L2
	call	__stack_chk_fail
.L2:
	leal	-12(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.section	.rodata
.LC16:
	.string	"I am function1"
	.text
	.globl	fun1
	.type	fun1, @function
fun1:
.LFB3:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$.LC16, (%esp)
	call	puts
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE3:
	.size	fun1, .-fun1
	.globl	idata5
	.data
	.align 4
	.type	idata5, @object
	.size	idata5, 4
idata5:
	.long	10
	.section	.rodata
.LC17:
	.string	"I am function2"
	.text
	.globl	fun2
	.type	fun2, @function
fun2:
.LFB4:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$.LC17, (%esp)
	call	puts
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE4:
	.size	fun2, .-fun2
	.section	.rodata
.LC18:
	.string	"I am function3"
	.text
	.globl	fun3
	.type	fun3, @function
fun3:
.LFB5:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$10, -12(%ebp)
	movl	$.LC18, (%esp)
	call	puts
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE5:
	.size	fun3, .-fun3
	.globl	idata6
	.data
	.align 4
	.type	idata6, @object
	.size	idata6, 4
idata6:
	.long	20
	.align 4
	.type	sdata2.2363, @object
	.size	sdata2.2363, 4
sdata2.2363:
	.long	10
	.local	sdata1.2362
	.comm	sdata1.2362,4,4
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
