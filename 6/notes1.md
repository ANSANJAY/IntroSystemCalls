entry_INT80_32
---------------

Arguments:
 eax  system call number
 ebx  arg1
 ecx  arg2
 edx  arg3
 esi  arg4
 edi  arg5
 ebp  arg6

stores the values of the registers on the stack
call do_int80_syscall_32
registers are restored
call iret               //#define INTERRUPT_RETURN iret

 void do_int80_syscall_32(struct pt_regs *regs)
{
        enter_from_user_mode();
        local_irq_enable();
        do_syscall_32_irqs_on(regs);
}

Activates the interrupt
Calls another function which gets a function from syscall table and calls it with syscall arguments.

                regs->ax = ia32_sys_call_table[nr](
                        (unsigned int)regs->bx, (unsigned int)regs->cx,
                        (unsigned int)regs->dx, (unsigned int)regs->si,
                        (unsigned int)regs->di, (unsigned int)regs->bp);

