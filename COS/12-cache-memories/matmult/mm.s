	.file	"mm.c"
	.text
	.comm	ga,6792800,32
	.comm	gb,6792800,32
	.comm	gc,6792800,32
	.section	.rodata
	.align 8
.LC0:
	.string	"Error: bad number (%f) in result matrix (%d,%d)\n"
	.text
	.globl	checkresult
	.type	checkresult, @function
checkresult:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	$0, -8(%rbp)
	jmp	.L2
.L7:
	movl	$0, -4(%rbp)
	jmp	.L3
.L6:
	movl	-8(%rbp), %eax
	cltq
	imulq	$9704, %rax, %rdx
	movq	-24(%rbp), %rax
	addq	%rax, %rdx
	movl	-4(%rbp), %eax
	cltq
	movsd	(%rdx,%rax,8), %xmm1
	cvtsi2sd	-28(%rbp), %xmm0
	ucomisd	%xmm0, %xmm1
	jp	.L8
	ucomisd	%xmm0, %xmm1
	je	.L9
.L8:
	movl	-8(%rbp), %eax
	cltq
	imulq	$9704, %rax, %rdx
	movq	-24(%rbp), %rax
	addq	%rax, %rdx
	movl	-4(%rbp), %eax
	cltq
	movq	(%rdx,%rax,8), %rax
	movl	-4(%rbp), %edx
	movl	-8(%rbp), %ecx
	movl	%ecx, %esi
	movq	%rax, -40(%rbp)
	movsd	-40(%rbp), %xmm0
	leaq	.LC0(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movq	stdout(%rip), %rax
	movq	%rax, %rdi
	call	fflush@PLT
	movl	$0, %edi
	call	exit@PLT
.L9:
	addl	$1, -4(%rbp)
.L3:
	movl	-4(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jl	.L6
	addl	$1, -8(%rbp)
.L2:
	movl	-8(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jl	.L7
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	checkresult, .-checkresult
	.globl	run
	.type	run, @function
run:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	-28(%rbp), %ecx
	movq	-24(%rbp), %rax
	movl	$1, %edx
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	fcyc@PLT
	movapd	%xmm0, %xmm1
	movl	-28(%rbp), %eax
	imull	-28(%rbp), %eax
	imull	-28(%rbp), %eax
	cvtsi2sd	%eax, %xmm0
	divsd	%xmm0, %xmm1
	movapd	%xmm1, %xmm0
	movsd	%xmm0, -8(%rbp)
	movl	-28(%rbp), %eax
	movl	%eax, %esi
	leaq	gc(%rip), %rdi
	call	checkresult
	movsd	-8(%rbp), %xmm0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	run, .-run
	.globl	reset
	.type	reset, @function
reset:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	$0, -8(%rbp)
	jmp	.L13
.L16:
	movl	$0, -4(%rbp)
	jmp	.L14
.L15:
	movl	-8(%rbp), %eax
	cltq
	imulq	$9704, %rax, %rdx
	movq	-24(%rbp), %rax
	addq	%rax, %rdx
	movl	-4(%rbp), %eax
	cltq
	pxor	%xmm0, %xmm0
	movsd	%xmm0, (%rdx,%rax,8)
	addl	$1, -4(%rbp)
.L14:
	movl	-4(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jl	.L15
	addl	$1, -8(%rbp)
.L13:
	movl	-8(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jl	.L16
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	reset, .-reset
	.globl	init
	.type	init, @function
init:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movl	%edx, -36(%rbp)
	movl	$0, -8(%rbp)
	jmp	.L18
.L21:
	movl	$0, -4(%rbp)
	jmp	.L19
.L20:
	movl	-8(%rbp), %eax
	cltq
	imulq	$9704, %rax, %rdx
	movq	-24(%rbp), %rax
	addq	%rax, %rdx
	movl	-4(%rbp), %eax
	cltq
	movsd	.LC2(%rip), %xmm0
	movsd	%xmm0, (%rdx,%rax,8)
	movl	-8(%rbp), %eax
	cltq
	imulq	$9704, %rax, %rdx
	movq	-32(%rbp), %rax
	addq	%rax, %rdx
	movl	-4(%rbp), %eax
	cltq
	movsd	.LC2(%rip), %xmm0
	movsd	%xmm0, (%rdx,%rax,8)
	addl	$1, -4(%rbp)
.L19:
	movl	-4(%rbp), %eax
	cmpl	-36(%rbp), %eax
	jl	.L20
	addl	$1, -8(%rbp)
.L18:
	movl	-8(%rbp), %eax
	cmpl	-36(%rbp), %eax
	jl	.L21
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	init, .-init
	.section	.rodata
.LC3:
	.string	"%5.1f "
	.text
	.globl	printarray
	.type	printarray, @function
printarray:
.LFB9:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	$0, -8(%rbp)
	jmp	.L23
.L26:
	movl	$0, -4(%rbp)
	jmp	.L24
.L25:
	movl	-8(%rbp), %eax
	cltq
	imulq	$9704, %rax, %rdx
	movq	-24(%rbp), %rax
	addq	%rax, %rdx
	movl	-4(%rbp), %eax
	cltq
	movq	(%rdx,%rax,8), %rax
	movq	%rax, -40(%rbp)
	movsd	-40(%rbp), %xmm0
	leaq	.LC3(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	addl	$1, -4(%rbp)
.L24:
	movl	-4(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jl	.L25
	movl	$10, %edi
	call	putchar@PLT
	addl	$1, -8(%rbp)
.L23:
	movl	-8(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jl	.L26
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	printarray, .-printarray
	.globl	ijk
	.type	ijk, @function
ijk:
.LFB10:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%rdx, -56(%rbp)
	movl	%ecx, -60(%rbp)
	movl	$0, -20(%rbp)
	jmp	.L28
.L33:
	movl	$0, -16(%rbp)
	jmp	.L29
.L32:
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -8(%rbp)
	movl	$0, -12(%rbp)
	jmp	.L30
.L31:
	movl	-20(%rbp), %eax
	cltq
	imulq	$9704, %rax, %rdx
	movq	-40(%rbp), %rax
	addq	%rax, %rdx
	movl	-12(%rbp), %eax
	cltq
	movsd	(%rdx,%rax,8), %xmm1
	movl	-12(%rbp), %eax
	cltq
	imulq	$9704, %rax, %rdx
	movq	-48(%rbp), %rax
	addq	%rax, %rdx
	movl	-16(%rbp), %eax
	cltq
	movsd	(%rdx,%rax,8), %xmm0
	mulsd	%xmm1, %xmm0
	movsd	-8(%rbp), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -8(%rbp)
	addl	$1, -12(%rbp)
.L30:
	movl	-12(%rbp), %eax
	cmpl	-60(%rbp), %eax
	jl	.L31
	movl	-20(%rbp), %eax
	cltq
	imulq	$9704, %rax, %rdx
	movq	-56(%rbp), %rax
	addq	%rax, %rdx
	movl	-16(%rbp), %eax
	cltq
	movsd	(%rdx,%rax,8), %xmm0
	movl	-20(%rbp), %eax
	cltq
	imulq	$9704, %rax, %rdx
	movq	-56(%rbp), %rax
	addq	%rax, %rdx
	addsd	-8(%rbp), %xmm0
	movl	-16(%rbp), %eax
	cltq
	movsd	%xmm0, (%rdx,%rax,8)
	addl	$1, -16(%rbp)
.L29:
	movl	-16(%rbp), %eax
	cmpl	-60(%rbp), %eax
	jl	.L32
	addl	$1, -20(%rbp)
.L28:
	movl	-20(%rbp), %eax
	cmpl	-60(%rbp), %eax
	jl	.L33
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	ijk, .-ijk
	.globl	jik
	.type	jik, @function
jik:
.LFB11:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%rdx, -56(%rbp)
	movl	%ecx, -60(%rbp)
	movl	$0, -16(%rbp)
	jmp	.L35
.L40:
	movl	$0, -20(%rbp)
	jmp	.L36
.L39:
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -8(%rbp)
	movl	$0, -12(%rbp)
	jmp	.L37
.L38:
	movl	-20(%rbp), %eax
	cltq
	imulq	$9704, %rax, %rdx
	movq	-40(%rbp), %rax
	addq	%rax, %rdx
	movl	-12(%rbp), %eax
	cltq
	movsd	(%rdx,%rax,8), %xmm1
	movl	-12(%rbp), %eax
	cltq
	imulq	$9704, %rax, %rdx
	movq	-48(%rbp), %rax
	addq	%rax, %rdx
	movl	-16(%rbp), %eax
	cltq
	movsd	(%rdx,%rax,8), %xmm0
	mulsd	%xmm1, %xmm0
	movsd	-8(%rbp), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -8(%rbp)
	addl	$1, -12(%rbp)
.L37:
	movl	-12(%rbp), %eax
	cmpl	-60(%rbp), %eax
	jl	.L38
	movl	-20(%rbp), %eax
	cltq
	imulq	$9704, %rax, %rdx
	movq	-56(%rbp), %rax
	addq	%rax, %rdx
	movl	-16(%rbp), %eax
	cltq
	movsd	(%rdx,%rax,8), %xmm0
	movl	-20(%rbp), %eax
	cltq
	imulq	$9704, %rax, %rdx
	movq	-56(%rbp), %rax
	addq	%rax, %rdx
	addsd	-8(%rbp), %xmm0
	movl	-16(%rbp), %eax
	cltq
	movsd	%xmm0, (%rdx,%rax,8)
	addl	$1, -20(%rbp)
.L36:
	movl	-20(%rbp), %eax
	cmpl	-60(%rbp), %eax
	jl	.L39
	addl	$1, -16(%rbp)
.L35:
	movl	-16(%rbp), %eax
	cmpl	-60(%rbp), %eax
	jl	.L40
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	jik, .-jik
	.globl	ikj
	.type	ikj, @function
ikj:
.LFB12:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%rdx, -56(%rbp)
	movl	%ecx, -60(%rbp)
	movl	$0, -20(%rbp)
	jmp	.L42
.L47:
	movl	$0, -12(%rbp)
	jmp	.L43
.L46:
	movl	-20(%rbp), %eax
	cltq
	imulq	$9704, %rax, %rdx
	movq	-40(%rbp), %rax
	addq	%rax, %rdx
	movl	-12(%rbp), %eax
	cltq
	movsd	(%rdx,%rax,8), %xmm0
	movsd	%xmm0, -8(%rbp)
	movl	$0, -16(%rbp)
	jmp	.L44
.L45:
	movl	-20(%rbp), %eax
	cltq
	imulq	$9704, %rax, %rdx
	movq	-56(%rbp), %rax
	addq	%rax, %rdx
	movl	-16(%rbp), %eax
	cltq
	movsd	(%rdx,%rax,8), %xmm1
	movl	-12(%rbp), %eax
	cltq
	imulq	$9704, %rax, %rdx
	movq	-48(%rbp), %rax
	addq	%rax, %rdx
	movl	-16(%rbp), %eax
	cltq
	movsd	(%rdx,%rax,8), %xmm0
	mulsd	-8(%rbp), %xmm0
	movl	-20(%rbp), %eax
	cltq
	imulq	$9704, %rax, %rdx
	movq	-56(%rbp), %rax
	addq	%rax, %rdx
	addsd	%xmm1, %xmm0
	movl	-16(%rbp), %eax
	cltq
	movsd	%xmm0, (%rdx,%rax,8)
	addl	$1, -16(%rbp)
.L44:
	movl	-16(%rbp), %eax
	cmpl	-60(%rbp), %eax
	jl	.L45
	addl	$1, -12(%rbp)
.L43:
	movl	-12(%rbp), %eax
	cmpl	-60(%rbp), %eax
	jl	.L46
	addl	$1, -20(%rbp)
.L42:
	movl	-20(%rbp), %eax
	cmpl	-60(%rbp), %eax
	jl	.L47
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	ikj, .-ikj
	.globl	kij
	.type	kij, @function
kij:
.LFB13:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%rdx, -56(%rbp)
	movl	%ecx, -60(%rbp)
	movl	$0, -12(%rbp)
	jmp	.L49
.L54:
	movl	$0, -20(%rbp)
	jmp	.L50
.L53:
	movl	-20(%rbp), %eax
	cltq
	imulq	$9704, %rax, %rdx
	movq	-40(%rbp), %rax
	addq	%rax, %rdx
	movl	-12(%rbp), %eax
	cltq
	movsd	(%rdx,%rax,8), %xmm0
	movsd	%xmm0, -8(%rbp)
	movl	$0, -16(%rbp)
	jmp	.L51
.L52:
	movl	-20(%rbp), %eax
	cltq
	imulq	$9704, %rax, %rdx
	movq	-56(%rbp), %rax
	addq	%rax, %rdx
	movl	-16(%rbp), %eax
	cltq
	movsd	(%rdx,%rax,8), %xmm1
	movl	-12(%rbp), %eax
	cltq
	imulq	$9704, %rax, %rdx
	movq	-48(%rbp), %rax
	addq	%rax, %rdx
	movl	-16(%rbp), %eax
	cltq
	movsd	(%rdx,%rax,8), %xmm0
	mulsd	-8(%rbp), %xmm0
	movl	-20(%rbp), %eax
	cltq
	imulq	$9704, %rax, %rdx
	movq	-56(%rbp), %rax
	addq	%rax, %rdx
	addsd	%xmm1, %xmm0
	movl	-16(%rbp), %eax
	cltq
	movsd	%xmm0, (%rdx,%rax,8)
	addl	$1, -16(%rbp)
.L51:
	movl	-16(%rbp), %eax
	cmpl	-60(%rbp), %eax
	jl	.L52
	addl	$1, -20(%rbp)
.L50:
	movl	-20(%rbp), %eax
	cmpl	-60(%rbp), %eax
	jl	.L53
	addl	$1, -12(%rbp)
.L49:
	movl	-12(%rbp), %eax
	cmpl	-60(%rbp), %eax
	jl	.L54
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE13:
	.size	kij, .-kij
	.globl	kji
	.type	kji, @function
kji:
.LFB14:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%rdx, -56(%rbp)
	movl	%ecx, -60(%rbp)
	movl	$0, -12(%rbp)
	jmp	.L56
.L61:
	movl	$0, -16(%rbp)
	jmp	.L57
.L60:
	movl	-12(%rbp), %eax
	cltq
	imulq	$9704, %rax, %rdx
	movq	-48(%rbp), %rax
	addq	%rax, %rdx
	movl	-16(%rbp), %eax
	cltq
	movsd	(%rdx,%rax,8), %xmm0
	movsd	%xmm0, -8(%rbp)
	movl	$0, -20(%rbp)
	jmp	.L58
.L59:
	movl	-20(%rbp), %eax
	cltq
	imulq	$9704, %rax, %rdx
	movq	-56(%rbp), %rax
	addq	%rax, %rdx
	movl	-16(%rbp), %eax
	cltq
	movsd	(%rdx,%rax,8), %xmm1
	movl	-20(%rbp), %eax
	cltq
	imulq	$9704, %rax, %rdx
	movq	-40(%rbp), %rax
	addq	%rax, %rdx
	movl	-12(%rbp), %eax
	cltq
	movsd	(%rdx,%rax,8), %xmm0
	mulsd	-8(%rbp), %xmm0
	movl	-20(%rbp), %eax
	cltq
	imulq	$9704, %rax, %rdx
	movq	-56(%rbp), %rax
	addq	%rax, %rdx
	addsd	%xmm1, %xmm0
	movl	-16(%rbp), %eax
	cltq
	movsd	%xmm0, (%rdx,%rax,8)
	addl	$1, -20(%rbp)
.L58:
	movl	-20(%rbp), %eax
	cmpl	-60(%rbp), %eax
	jl	.L59
	addl	$1, -16(%rbp)
.L57:
	movl	-16(%rbp), %eax
	cmpl	-60(%rbp), %eax
	jl	.L60
	addl	$1, -12(%rbp)
.L56:
	movl	-12(%rbp), %eax
	cmpl	-60(%rbp), %eax
	jl	.L61
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE14:
	.size	kji, .-kji
	.globl	jki
	.type	jki, @function
jki:
.LFB15:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%rdx, -56(%rbp)
	movl	%ecx, -60(%rbp)
	movl	$0, -16(%rbp)
	jmp	.L63
.L68:
	movl	$0, -12(%rbp)
	jmp	.L64
.L67:
	movl	-12(%rbp), %eax
	cltq
	imulq	$9704, %rax, %rdx
	movq	-48(%rbp), %rax
	addq	%rax, %rdx
	movl	-16(%rbp), %eax
	cltq
	movsd	(%rdx,%rax,8), %xmm0
	movsd	%xmm0, -8(%rbp)
	movl	$0, -20(%rbp)
	jmp	.L65
.L66:
	movl	-20(%rbp), %eax
	cltq
	imulq	$9704, %rax, %rdx
	movq	-56(%rbp), %rax
	addq	%rax, %rdx
	movl	-16(%rbp), %eax
	cltq
	movsd	(%rdx,%rax,8), %xmm1
	movl	-20(%rbp), %eax
	cltq
	imulq	$9704, %rax, %rdx
	movq	-40(%rbp), %rax
	addq	%rax, %rdx
	movl	-12(%rbp), %eax
	cltq
	movsd	(%rdx,%rax,8), %xmm0
	mulsd	-8(%rbp), %xmm0
	movl	-20(%rbp), %eax
	cltq
	imulq	$9704, %rax, %rdx
	movq	-56(%rbp), %rax
	addq	%rax, %rdx
	addsd	%xmm1, %xmm0
	movl	-16(%rbp), %eax
	cltq
	movsd	%xmm0, (%rdx,%rax,8)
	addl	$1, -20(%rbp)
.L65:
	movl	-20(%rbp), %eax
	cmpl	-60(%rbp), %eax
	jl	.L66
	addl	$1, -12(%rbp)
.L64:
	movl	-12(%rbp), %eax
	cmpl	-60(%rbp), %eax
	jl	.L67
	addl	$1, -16(%rbp)
.L63:
	movl	-16(%rbp), %eax
	cmpl	-60(%rbp), %eax
	jl	.L68
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE15:
	.size	jki, .-jki
	.section	.rodata
.LC4:
	.string	"matmult cycles/loop iteration"
.LC5:
	.string	"jik"
.LC6:
	.string	"ijk"
.LC7:
	.string	"kji"
.LC8:
	.string	"jki"
.LC9:
	.string	"n"
.LC10:
	.string	"%3s%6s%6s%6s%6s%6s%6s\n"
.LC11:
	.string	"ikj"
.LC12:
	.string	"kij"
.LC13:
	.string	"%3d "
.LC14:
	.string	"%5.2f "
	.text
	.globl	main
	.type	main, @function
main:
.LFB16:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$700, %edx
	leaq	gb(%rip), %rsi
	leaq	ga(%rip), %rdi
	call	init
	leaq	.LC4(%rip), %rdi
	call	puts@PLT
	leaq	.LC11(%rip), %rax
	pushq	%rax
	leaq	.LC12(%rip), %rax
	pushq	%rax
	leaq	.LC5(%rip), %r9
	leaq	.LC6(%rip), %r8
	leaq	.LC7(%rip), %rcx
	leaq	.LC8(%rip), %rdx
	leaq	.LC9(%rip), %rsi
	leaq	.LC10(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	addq	$16, %rsp
	movq	stdout(%rip), %rax
	movq	%rax, %rdi
	call	fflush@PLT
	movl	$50, -4(%rbp)
	jmp	.L70
.L71:
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC13(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	jki(%rip), %rdi
	call	run
	leaq	.LC14(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	kji(%rip), %rdi
	call	run
	leaq	.LC14(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	ijk(%rip), %rdi
	call	run
	leaq	.LC14(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	jik(%rip), %rdi
	call	run
	leaq	.LC14(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	kij(%rip), %rdi
	call	run
	leaq	.LC14(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	ikj(%rip), %rdi
	call	run
	leaq	.LC14(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movl	$10, %edi
	call	putchar@PLT
	movq	stdout(%rip), %rax
	movq	%rax, %rdi
	call	fflush@PLT
	addl	$50, -4(%rbp)
.L70:
	cmpl	$700, -4(%rbp)
	jle	.L71
	movl	$0, %edi
	call	exit@PLT
	.cfi_endproc
.LFE16:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC2:
	.long	0
	.long	1072693248
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
