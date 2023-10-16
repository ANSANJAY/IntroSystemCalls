How does the address of __kernel_vsyscall is determined?
----------------------------------------------------------

Userland processes (or C library on their behalf) call __kernel_vsyscall to execute system calls.

Address of __kernel_vsyscall is not fixed

Kernel passes this address to userland processes using AT_SYSINFO elf parameter

What are ELF Auxiliary Vectors?
-------------------------------

ELF auxiliary vectors are a mechanism to transfer certain kernel level information to the user processes.
Ex: AT_SYSINFO

It is a list of key-value pairs that the kernel's ELF binary loader (fs/binfmt_elf.c in the kernel source) constructs when a new executable image is loaded into a process.

The ELF loader 
	parses the ELF file, 
	maps the various program segments in the memory, 
	sets up the entry point and 
	initializes the process stack. 

It puts ELF auxiliary vectors on the process stack along with other information like argc, argv, envp

ELF loader puts an array (auxv) of ELF auxiliary vectors at the bottom of the stack.

To observe ELF Auxiliary Vectors
--------------------------------

There are a few methods for searching ELF auxilliary vectors:

	1. By using getauxval with the AT_SYSINFO argument. ( man 3 getauxval)
	2. By iterating to the end of the environment variables and parsing them from memory.

From Shell, we can discover the auxiliary vector that was supplied to an executable by setting the LD_SHOW_AUXV environment variable when launching an application
$ LD_SHOW_AUXV=1 ./binary

$ gcc userprog.c -o userprog -m32

ex: LD_SHOW_AUXV=1  /bin/ls

