	.file	"prog.c"
	.text
	.p2align 4,,15
	.globl	bubble_sort
	.type	bubble_sort, @function

# basic block 1
bubble_sort:
# basic block 2
.LFB20:
	.cfi_startproc
	addq $2, insn_count 				# 2 insns
	testl	%esi, %esi
	jle	.L1
	# basic block 3
	addq $4, insn_count 				# 4 insns
	leal	-2(%rsi), %eax
	cmpl	$1, %esi
	leaq	4(%rdi,%rax,4), %r8
	jne	.L17

# basic block 4
.L1:
	addq $1, insn_count 				# 1 insn
	rep ret
	
# basic block 5
.L17:
	addq $1, insn_count 				# 1 insn
	xorl	%r10d, %r10d
	.p2align 4,,10
	.p2align 3

# basic block 6
.L4:
	addq $2, insn_count 				# 2 insns
	movq	%rdi, %rax
	xorl	%r9d, %r9d
	.p2align 4,,10
	.p2align 3
	
# basic block 7
.L8:
	addq $4, insn_count 				# 4 insns
	movl	(%rax), %ecx
	movl	4(%rax), %edx
	cmpl	%edx, %ecx
	jle	.L5
	# basic block 8
	addq $3, insn_count 				# 3 insns
	movl	%ecx, 4(%rax)
	movl	%edx, (%rax)
	movl	$1, %r9d

# basic block 9
.L5:
	addq $3, insn_count 				# 3 insns
	addq	$4, %rax
	cmpq	%r8, %rax
	jne	.L8
	# basic block 10
	addq $2, insn_count 				# 2 insns
	testl	%r9d, %r9d
	je	.L1
	# basic block 11
	addq $3, insn_count 				# 3 insns
	addl	$1, %r10d
	cmpl	%esi, %r10d
	jne	.L4
	# basic block 12
	addq $1, insn_count 				# 1 insn
	rep ret
	.cfi_endproc

# basic block 13 (purely contains assembler directives)
.LFE20:
	.size	bubble_sort, .-bubble_sort
	.p2align 4,,15
	.globl	check_sorted
	.type	check_sorted, @function

# basic block 14
check_sorted:
# basic block 15
.LFB21:
	.cfi_startproc
	addq $2, insn_count 				# 2 insns
	cmpl	$1, %esi
	jle	.L22
	# basic block 16
	addq $3, insn_count 				# 3 insns
	movl	4(%rdi), %eax
	cmpl	%eax, (%rdi)
	jg	.L24
	# basic block 17
	addq $4, insn_count 				# 4 insns
	leal	-2(%rsi), %eax
	addq	$4, %rdi
	leaq	(%rdi,%rax,4), %rdx
	jmp	.L20
	.p2align 4,,10
	.p2align 3

# basic block 18
.L21:
	addq $4, insn_count 				# 4 insns
	movl	(%rdi), %eax
	addq	$4, %rdi
	cmpl	(%rdi), %eax
	jg	.L24

# basic block 19
.L20:
	addq $2, insn_count 				# 2 insns
	cmpq	%rdx, %rdi
	jne	.L21

# basic block 20
.L22:
	addq $2, insn_count 				# 2 insns
	movl	$1, %eax
	ret
	.p2align 4,,10
	.p2align 3

# basic block 21
.L24:
	addq $2, insn_count 				# 2 insns
	xorl	%eax, %eax
	ret
	.cfi_endproc

# blocks 22-24 purely contains assembler directives
# basic block 22
.LFE21:
	.size	check_sorted, .-check_sorted
	.section	.rodata.str1.1,"aMS",@progbits,1

# - block containing the string for instructions executed
.LC0:
	.string	"%lld instructions executed"

# basic block 23
.LC1:
	.string	"numbers are sorted"

# basic block 24
.LC2:
	.string	"numbers are not sorted"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function

# basic block 25
main:
# basic block 26
.LFB22:
	.cfi_startproc
	addq $2, insn_count 				# 2 insns
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$numbers, %ebx
	.p2align 4,,10
	.p2align 3

# basic block 27
.L27:
	addq $5, insn_count 				# 5 insns
	call	rand
	addq	$4, %rbx
	movl	%eax, -4(%rbx)
	cmpq	$numbers+40000, %rbx
	jne	.L27
	# basic block 28
	addq $6, insn_count 				# 6 insns
	movl	$10000, %esi
	movl	$numbers, %edi
	call	bubble_sort
	movl	$numbers+4, %eax
	movl	numbers(%rip), %ecx
	jmp	.L30
	.p2align 4,,10
	.p2align 3
# basic block 29
.L33:
	addq $3, insn_count 				# 3 insns
	addq	$4, %rax
	cmpq	$numbers+40000, %rax
	je	.L29
	# basic block 30
	addq $1, insn_count 				# 1 insn
	movl	%edx, %ecx

# basic block 31
.L30:
	addq $3, insn_count 				# 3 insns
	movl	(%rax), %edx
	cmpl	%ecx, %edx
	jge	.L33
	# basic block 32
	addq $2, insn_count 				# 2 insns
	movl	$.LC2, %edi
	call	puts

# basic block 33
.L31:
	addq $6, insn_count 				# 6 insns
	movq	insn_count(%rip), %rsi
	movl	$.LC0, %edi
	xorl	%eax, %eax
	call	printf
	xorl	%edi, %edi
	call	exit

# basic block 34
.L29:
	addq $3, insn_count 				# 3 insns
	movl	$.LC1, %edi
	call	puts
	jmp	.L31
	.cfi_endproc

# basic block 35 (purely contains assembler directives)
.LFE22:
	.size	main, .-main
	.comm	numbers,40000,32
	.globl	insn_count
	.bss
	.align 16
	.type	insn_count, @object
	.size	insn_count, 8


insn_count:
	.zero	8
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-44)"
	.section	.note.GNU-stack,"",@progbits
