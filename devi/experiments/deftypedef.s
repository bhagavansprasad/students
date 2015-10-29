	.file	"deftypedef.c"
	.section	.rodata
.LC0:
	.string	"sizeof a:%u\n"
.LC1:
	.string	"sizeof b:%u\n"
.LC2:
	.string	"sizeof c:%u\n"
.LC3:
	.string	"sizeof x:%u\n"
.LC4:
	.string	"sizeof y:%u\n"
.LC5:
	.string	"sizeof z:%u\n"
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
	subl	$16, %esp
	movl	$4, 4(%esp)
	movl	$.LC0, (%esp)
	call	printf
	movl	$4, 4(%esp)
	movl	$.LC1, (%esp)
	call	printf
	movl	$4, 4(%esp)
	movl	$.LC2, (%esp)
	call	printf
	movl	$4, 4(%esp)
	movl	$.LC3, (%esp)
	call	printf
	movl	$1, 4(%esp)
	movl	$.LC4, (%esp)
	call	printf
	movl	$1, 4(%esp)
	movl	$.LC5, (%esp)
	call	printf
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
