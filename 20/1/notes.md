vDSO (Virtual Dynamic Shared Object)
======================================

What is vDSO?
==============

The  "vDSO" (virtual dynamic shared object) is a small shared library that the kernel automatically maps
into the address space of all user-space applications.

Why does the vDSO exist at all?
================================

communication between userspace applications and the kernel is through system calls.
Eg. fork(), vfork() etc

When a process invokes a system call:

1. it executes a special instruction forcing the CPU to switch to kernel mode
2. saves the contents of the registers on the kernel mode stack
3. starts the execution of a kernel function
4. When the system call has been serviced, the kernel restores the contents of the registers saved on the kernel mode stack
5. executes another special instruction to resume execution of the user-space process.

Numerous clock cycles are spent just to make these special kind of function calls.


Issue
=============

There are some system calls the kernel provides that user-space code ends up using frequently, to the point that such calls can dominate overall performance

Eg. gettimeofday()

	Performance is reduced due to 
	1. Frequency of the call
	2. Context-switch overhead that results from exiting user space and entering the kernel.

	Certain functions that do not write any data and merely return a value stored in the kernel, such as gettimeofday(), are relatively safe in nature.

	With vDSO, the kernel arranges for the required information to be placed in memory the  process can  access.

	Now  a call to gettimeofday(2) changes from a system call to a normal function call and a few memory accesses

