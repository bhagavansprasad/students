	.file	"25fun2.c"
	.globl	idata5
	.data
	.align 4
	.type	idata5, @object
	.size	idata5, 4
idata5:
	.long	10
	.section	.rodata
.LC0:
	.string	"I am function2"
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
	subl	$24, %esp
	movl	$.LC0, (%esp)
	call	puts
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	fun2, .-fun2
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
