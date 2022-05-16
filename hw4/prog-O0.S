	.file	"prog.c"
	.text
	.globl	bubble_sort
	.type	bubble_sort, @function
	.globl	insn_count
	.bss

insn_count:
	.zero	8
	.text
	.globl	insn_count

# basic block 1
bubble_sort:
# basic block 2
.LFB2:
	.cfi_startproc
	addq $6, insn_count 				# 6 insns
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L2

# basic block 3
.L8:
	addq $3, insn_count 				# 3 insns
	movl	$0, -12(%rbp)
	movl	$1, -8(%rbp)
	jmp	.L3

# basic block 4
.L5:	
	addq $15, insn_count 				# 15 insns
	movl	-8(%rbp), %eax
	cltq
	salq	$2, %rax
	leaq	-4(%rax), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	movq	-24(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	jle	.L4
	# basic block 5
	addq $29, insn_count 				# 29 insns
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -16(%rbp)
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rax, %rdx
	movl	-8(%rbp), %eax
	cltq
	salq	$2, %rax
	leaq	-4(%rax), %rcx
	movq	-24(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %eax
	movl	%eax, (%rdx)
	movl	-8(%rbp), %eax
	cltq
	salq	$2, %rax
	leaq	-4(%rax), %rdx
	movq	-24(%rbp), %rax
	addq	%rax, %rdx
	movl	-16(%rbp), %eax
	movl	%eax, (%rdx)
	movl	$1, -12(%rbp)

# basic block 6
.L4:
	addq $1, insn_count 				# 1 insn
	addl	$1, -8(%rbp)

# basic block 7
.L3:
	addq $3, insn_count 				# 3 insns
	movl	-8(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jl	.L5
	# basic block 8
	addq $3, insn_count 				# 3 insns
	cmpl	$0, -12(%rbp)
	jne	.L6
	jmp	.L1

# basic block 9
.L6:
	addq $1, insn_count 				# 1 insn
	addl	$1, -4(%rbp)

# basic block 10
.L2:
	addq $3, insn_count 				# 3 insns
	movl	-4(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jl	.L8

# basic block 11
.L1:
	addq $2, insn_count 				# 2 insns
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc

.LFE2:
	.size	bubble_sort, .-bubble_sort
	.globl	check_sorted
	.type	check_sorted, @function

# basic block 12
check_sorted:
# basic block 13
.LFB3:
	.cfi_startproc
	addq $6, insn_count 				# 6 insns
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	$1, -4(%rbp)
	jmp	.L10

# basic block 14
.L13:
	addq $15, insn_count 				# 15 insns
	movl	-4(%rbp), %eax
	cltq
	salq	$2, %rax
	leaq	-4(%rax), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	movq	-24(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	jle	.L11
	# basic block 15
	addq $2, insn_count 				# 2 insns
	movl	$0, %eax
	jmp	.L12

# basic block 16
.L11:
	addq $1, insn_count 				# 1 insn
	addl	$1, -4(%rbp)

# basic block 17
.L10:
	addq $3, insn_count 				# 3 insns
	movl	-4(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jl	.L13
	# basic block 18
	addq $1, insn_count 				# 1 insn
	movl	$1, %eax

# basic block 19
.L12:
	addq $2, insn_count 				# 2 insns
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc

# blocks 20-22 contain assembler directives
# basic block 20
.LFE3:
	.size	check_sorted, .-check_sorted
	.comm	numbers,40000,32
	.section	.rodata

# basic block 21
.LC0:
	.string	"numbers are sorted"

# basic block 22
.LC1:
	.string	"numbers are not sorted"
	.text
	.globl	main
	.type	main, @function

# block containing the string for %lld instructions executed
.LC2:
	.string	"%lld instructions executed"
	.text
	.globl	main
	.type	main, @function

# basic block 23
main:
# basic block 24
.LFB4:
	.cfi_startproc
	addq $5, insn_count 				# 5 insns
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$0, -4(%rbp)
	jmp	.L15

# basic block 25
.L16:
	addq $5, insn_count 				# 5 insns
	call	rand
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	movl	%eax, numbers(,%rdx,4)
	addl	$1, -4(%rbp)

# basic block 26
.L15:
	addq $2, insn_count 				# 2 insns
	cmpl	$9999, -4(%rbp)
	jle	.L16
	# basic block 27
	addq $8, insn_count 				# 8 insns
	movl	$10000, %esi
	movl	$numbers, %edi
	call	bubble_sort
	movl	$10000, %esi
	movl	$numbers, %edi
	call	check_sorted
	testl	%eax, %eax
	je	.L17
	# basic block 28
	addq $3, insn_count 				# 3 insns
	movl	$.LC0, %edi
	call	puts
	jmp	.L18

# basic block 29
.L17:
	addq $2, insn_count 				# 2 insns
	movl	$.LC1, %edi
	call	puts

# basic block 30
.L18:
	addq $7, insn_count 				# 7 insns
	movq	insn_count(%rip), %rax
	movq	%rax, %rsi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %edi
	call	exit
	.cfi_endproc

# basic block 31 (purely contains directives)
.LFE4:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-44)"
	.section	.note.GNU-stack,"",@progbits
