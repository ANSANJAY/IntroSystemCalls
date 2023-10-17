__kernel_vsyscall
------------------

When int 0x80 is issued, CPU saves eflags, eip, esp, ss and cs registers.

Then, it switches from user mode to kernel mode. Before eventually calling the syscall routine, the kernel saves remaining registers on the stack.

On the other hand, when sysenter opcode is issued, the CPU copies the content of three Model-Specific Registers (MSR):

	SYSENTER_CS_MSR			-->	cs
	SYSENTER_EIP_MSR		-->	eip
	SYSENTER_ESP_MSR		-->	esp

The current address on which eip is pointing is not saved.

The following registers needs to be saved before calling sysenter.
eip
ecx
edx
ebp

To avoid this, kernel implemented a function called __kernel_vsyscall. 

The __kernel_vsyscall( ) function saves on the User Mode stack the contents of ebp, edx, and ecx (these registers are going to be used by the system call handler), copies the user stack pointer in ebp, then executes the sysenter instruction.

arch/x86/entry/vdso/vdso32/system_call.S
arch/x86/entry/entry_32.S

How can we call __kernel_vsyscall from userspace
-------------------------------------------------

Kernel creates a single page in the memory and attaches it to all processes' address space when they are loaded into memory

Kernel calls this page virtual dynamic shared object (vdso). This has definition of __kernel_vsyscal

When you compile the kernel, it will automatically compile and link the vDSO code for you

You will frequently find it under the architecture-specific directory

$ find arch/$ARCH/ -name '*vdso*.so*'

$ nm vdso32.so.dbg | grep kernel_vsyscall

The address of the __kernel_vsyscall function is written into an ELF auxilliary vector where a user program or library (typically glibc) can find it and use it.




ldd on user space application shows (linux-vdso.so)
