Return value of system calls
-----------------------------

All system calls return long

Positive or 0 value denotes a successful termination of the system call

Negative value denotes an error condition.
        The value is the negation of the error code that must be returned to the application program in the errno
        variable.

The errno variable is not set or used by the Linux Kernel.
Instead, the wrapper routines handle the task of setting this variable after a return from a system call.
