On Linux, there are several ways to make a system calls

int $0x80
------------

Until some time back, linux used to implement system calls on all x86 platforms using software interrupts

To execute a system call user process will 
	copy desired system call number to %eax
	copy parameters if present into registers as per ABI
	execute int $0x80
	return value is read from %eax

This will generate interrupt 0x80 and an interrupt service routine will be called.

What happens in kernel space at int $0x80
------------------------------------------

x86 trap is registered for 0x80 in function idt_setup_traps(). File:arch/x86/kernel/idt.c

void __init idt_setup_traps(void)
{
        idt_setup_from_table(idt_table, def_idts, ARRAY_SIZE(def_idts), true);
}

static const __initconst struct idt_data def_idts[] = {
....
....

        SYSG(IA32_SYSCALL_VECTOR,       entry_INT80_32)


};

IA32_SYSCALL_VECTOR is simply a define for the number 128 (0x80)
#define IA32_SYSCALL_VECTOR             0x80

So, the function entry_INT80_32 is called (arch/x86/entry/entry_32.S)

