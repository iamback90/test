	.file	"test.c"
	.text
	.globl	g_int
	.data
	.align 4
	.type	g_int, @object
	.size	g_int, 4
g_int:
	.long	11
	.align 4
	.type	static_int, @object
	.size	static_int, 4
static_int:
	.long	22
	.text
	.globl	Test
	.type	Test, @function
Test:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	Test, .-Test
	.globl	Foo
	.type	Foo, @function
Foo:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	g(%rip), %edx
	movl	g_int(%rip), %eax
	addl	%eax, %edx
	movl	static_int(%rip), %eax
	addl	%edx, %eax
	movl	%eax, -4(%rbp)
	movl	g_int(%rip), %ecx
	movl	g(%rip), %eax
	movl	-4(%rbp), %edx
	movl	%ecx, %esi
	movl	%eax, %edi
	call	ExternFunc@PLT
	movl	$0, %eax
	call	Test
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	Foo, .-Foo
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
