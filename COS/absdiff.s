	.file	"absdiff.c"
	.text
	.globl	absdiff
	.type	absdiff, @function
absdiff:
.LFB23:
	.cfi_startproc
	cmpq	%rsi, %rdi
	jg	.L4
	movq	%rsi, %rax
	subq	%rdi, %rax
	ret
.L4:
	movq	%rdi, %rax
	subq	%rsi, %rax
	ret
	.cfi_endproc
.LFE23:
	.size	absdiff, .-absdiff
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
