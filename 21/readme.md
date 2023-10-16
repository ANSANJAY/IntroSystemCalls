vsyscalls
==============

The vsyscall or virtual system call is the first and oldest mechanism in the Linux kernel that is designed to accelerate execution of certain system calls. 

File: arch/x86/entry/vsyscall/vsyscall_emu_64.S 

System Calls:

    gettimeofday
    time
    getcpu

How it works
==============

The Linux kernel maps into user space a page that contains some variables and the implementation of some system calls.

$ cat /proc/self/maps | grep vsyscall

Limitations
=============

1. space only for 4 system calls
2. security:
    Type cat /proc/self/maps multiple times
    Note that the vDSO area has moved, while the vsyscall page remains at the same location
    The location of the vsyscall page is nailed down in the kernel ABI, but the vDSO area is ASLR

Note: The security issue has been mitigated by emulating a virtual system call, but the emulation introduces additional latency.

vDSO is dynamically allocated, offers improved safety through memory space randomization, and supports more than 4 system calls. 

vDSO links are provided via the glibc library

If the kernel does not have vDSO support, a traditional syscall is made.


