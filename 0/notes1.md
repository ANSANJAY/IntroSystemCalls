What happens inside a system call
----------------------------------

A kernel code snippet is run on request of a user process.

This code runs in ring 0 (with current privilege level -CPL- 0), which is the highest level of privilege in x86 architecture.

All user processes run in ring 3 (CPL 3).

To implement system call mechanism, we need 
1) a way to call ring 0 code from ring 3 and 
2) some kernel code to service the request.
