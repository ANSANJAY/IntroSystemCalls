**entry_INT80_32**
- **Explain the technical concept**:
  - `entry_INT80_32` is a crucial part of the x86 architecture's system call mechanism. 
  When a program wishes to make a system call, it loads the appropriate registers with the syscall number and arguments and triggers an interrupt via the `int $0x80` instruction.
  - On receiving this interrupt, the `entry_INT80_32` routine is activated. This routine:
    1. Stores the values of the registers on its stack.
    2. Calls the `do_int80_syscall_32()` function.
    3. Restores the registers.
    4. Executes an `iret` (Interrupt Return) to return control to the calling user-mode process.
  - The `do_int80_syscall_32()` function carries out several tasks:
    1. Switches the processor to user mode.
    2. Enables local interrupts.
    3. Invokes `do_syscall_32_irqs_on()` which fetches the relevant system call handler from the syscall table based on the system call number (from `eax` or `regs->ax`) and then executes the handler with the provided arguments.



Arguments:
```bash
 eax  system call number
 ebx  arg1
 ecx  arg2
 edx  arg3
 esi  arg4
 edi  arg5
 ebp  arg6
```

stores the values of the registers on the stack
call do_int80_syscall_32
registers are restored
call iret               //#define INTERRUPT_RETURN iret

```C
 void do_int80_syscall_32(struct pt_regs *regs)
{
        enter_from_user_mode();
        local_irq_enable();
        do_syscall_32_irqs_on(regs);
}
```
Activates the interrupt
Calls another function which gets a function from syscall table and calls it with syscall arguments.
```C
                regs->ax = ia32_sys_call_table[nr](
                        (unsigned int)regs->bx, (unsigned int)regs->cx,
                        (unsigned int)regs->dx, (unsigned int)regs->si,
                        (unsigned int)regs->di, (unsigned int)regs->bp);
```


- **Curious Questions**:
  - **What's the significance of the interrupt enabling (`local_irq_enable()`) within the system call handler?**
    - Enabling interrupts ensures that the processor can handle other important tasks or events while the system call is being serviced. It's essential for maintaining system responsiveness.
  - **Why are the registers' values stored on the stack and later restored?**
    - This operation ensures the integrity of the user-space process's context. After the system call is serviced, the process should resume as if the system call were just another function, with all its previous register values intact.
  - **How does the kernel prevent unauthorized access or changes to the `ia32_sys_call_table`?**
    - The syscall table is typically stored in a section of memory that's write-protected, preventing malicious modification. Also, direct access to the kernel's internal structures, like the syscall table, is restricted from user mode.

- **Explain the concept in simple words**:
  - Picture a hotel concierge service 🏨🔔. When a guest (a program) rings the bell (using `int $0x80`), the concierge (the `entry_INT80_32` routine) notes down the guest's request and particulars. The concierge then consults their instruction manual (the syscall table) to carry out the guest's request. Once the task is done, the concierge returns any items (registers' values) they borrowed from the guest and allows the guest to continue their stay (returns to the user-mode process). The whole process ensures the guest's experience is seamless and uninterrupted.
