System Call Number
-----------------

Each and every system call has a system call number which is known by both the userspace and the kernel.

Example: read() has a system call number 3, open() has system call number 5

System call number is different for different architectures.

Example: exit() has a system call number 60 on x86_64 and 1 on x86

System Call Table
------------------

Kernel uses a table which maps the system call number to system call handler
This table is called as System Call Table.

Location of System Call Table
------------------------------

For x86: arch/x86/entry/syscalls/syscall_32.tbl
x86_64:  arch/x86/entry/syscalls/syscall_64.tbl
arm:	 arch/arm/tools/syscall.tbl






