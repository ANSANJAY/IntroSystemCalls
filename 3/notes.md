Difference between System Call and Function Call
--------------------------------------------------

System call code is run inside kernel, program has to switch from user mode into kernel mode.
        Switching to kernel mode can happen in different ways (eg. via syscall)

Special instructions are needed to make the processor perform a transition to ring 0 (privileged mode)

System call is identified by a system call number rather than function address

