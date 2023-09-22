64-bit fast system calls
------------------------

Instruction from CPL 3 to CPL 0 -- syscall
Instruction from CPL 0 to CPL 3 -- sysret

From Intel Manual:

"SYSCALL invokes an OS system-call handler at privilege level 0. It does so by loading RIP from the IA32_LSTAR MSR (after saving the address of the instruction following SYSCALL into RCX)."

In other words: for the kernel to receive incoming system calls, it must register the address of the code that will execute when a system call occurs by writing its address to the IA32_LSTAR MSR.

arch/x86/kernel/cpu/common.c

void syscall_init(void)
{
....

wrmsrl(MSR_LSTAR, (unsigned long)entry_SYSCALL_64);

}

call    do_syscall_64

__visible void do_syscall_64(unsigned long nr, struct pt_regs *regs)
{
        struct thread_info *ti;

        enter_from_user_mode();
        local_irq_enable();
        ti = current_thread_info();
        if (READ_ONCE(ti->flags) & _TIF_WORK_SYSCALL_ENTRY)
                nr = syscall_trace_enter(regs);

        /* 
         * NB: Native and x32 syscalls are dispatched from the same
         * table.  The only functional difference is the x32 bit in
         * regs->orig_ax, which changes the behavior of some syscalls.
         */
        nr &= __SYSCALL_MASK;
        if (likely(nr < NR_syscalls)) {
                nr = array_index_nospec(nr, NR_syscalls);
                regs->ax = sys_call_table[nr](regs);
        }

        syscall_return_slowpath(regs);

}




