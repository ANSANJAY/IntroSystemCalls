sysenter/sysexit
-----------------

From Intel manual
	The SYSENTER instruction is part of the "Fast System Call" facility introduced on the Pentium® II processor.
    The SYSENTER instruction is optimized to provide the maximum performance for transitions to protection ring 0 (CPL = 0).

	The SYSEXIT instruction is part of the "Fast System Call" facility introduced on the Pentium® II processor.
The SYSEXIT instruction is optimized to provide the maximum performance for transitions to protection ring 3 (CPL = 3) from protection ring 0 (CPL = 0).

Differences between legacy system call and sysenter
------------------------------------------------------
Using sysenter to make a system call is more complicated than using the legacy interrupt method.
It involves more coordination between the user program (via glibc) and the kernel.

Prior to executing the SYSENTER instruction, software must specify
        the privilege level 0 code segment
        code entry point
        the privilege level 0 stack segment and stack pointer

to the following MSRs

IA32_SYSENTER_CS (MSR address 174H)
IA32_SYSENTER_EIP (MSR address 176H)
        This MSR is where the kernel should specify the address of the function that will execute when a sysenter instruction is executed by a user program
IA32_SYSENTER_ESP (MSR address 175H)
From arch/x86/kernel/cpu/common.c

void enable_sep_cpu(void)
{
        struct tss_struct *tss;
        int cpu;

        if (!boot_cpu_has(X86_FEATURE_SEP))
                return;

        cpu = get_cpu();
        tss = &per_cpu(cpu_tss_rw, cpu);

        /* 
         * We cache MSR_IA32_SYSENTER_CS's value in the TSS's ss1 field --
         * see the big comment in struct x86_hw_tss's definition.
         */

        tss->x86_tss.ss1 = __KERNEL_CS;
        wrmsr(MSR_IA32_SYSENTER_CS, tss->x86_tss.ss1, 0);
        wrmsr(MSR_IA32_SYSENTER_ESP, (unsigned long)(cpu_entry_stack(cpu) + 1), 0);
        wrmsr(MSR_IA32_SYSENTER_EIP, (unsigned long)entry_SYSENTER_32, 0);
        put_cpu();
}



	
