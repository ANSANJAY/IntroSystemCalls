Fast System Calls
------------------

An interrupt is extremely expensive, especially when you invoke a system call like getpid() that only returns the value of one variable.

The newer method has the below advantages:
        a) Don't involve a software interrupt
        b) Much faster than using a software interrupt

The method comprises of two instructions.
        One to enter the kernel
        One to leave the kernel

On 32-bit Systems: sysenter and sysexit
On 64-bit systems: syscall and sysret

