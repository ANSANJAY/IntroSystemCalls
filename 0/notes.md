What is System Call
--------------------

System calls provide userspace processes a way to request services from the kernel.

	or

It is a way of requesting the kernel to do something on your behalf

What kind of services?
----------------------
Services which are managed by operating system like storage, memory, network, process management etc.

Examples of Kernel Service
1. Write/read file
2. Listen for connections on a socket
3. Create/Delete directory
4. creating and executing new processes,

On Unix systems, the C library provides wrapper around these system calls

What happens inside a system call
----------------------------------

A kernel code snippet is run on request of a user process.

This code runs in ring 0 (with current privilege level -CPL- 0), which is the highest level of privilege in x86 architecture.

All user processes run in ring 3 (CPL 3).

To implement system call mechanism, we need 
1) a way to call ring 0 code from ring 3 and 
2) some kernel code to service the request.
