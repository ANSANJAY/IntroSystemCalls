do_fast_syscall_32(struct pt_regs *regs) in arch/x86/entry/common.c

Finally calls do_syscall_32_irqs_on(regs);

Returning from a sysenter system call with sysexit
--------------------------------------------------

The kernel can use the sysexit instruction to resume execution back to the user program.

CS register set to the sum of (16 plus the value in SYSENTER_CS_MSR)
EIP register set to the value contained in the EDX register
SS register set to the sum of (24 plus the value in SYSENTER_CS_MSR)
ESP register set to the value contained in the ECX register
