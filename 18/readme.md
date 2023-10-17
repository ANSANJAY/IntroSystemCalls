syscall
-----------

syscall() is a small library function that invokes the system call
This is provided to use when invoking a system call that has no wrapper function in the C library.

syscall()
	saves CPU registers before making the system call
	restores the registers upon return from the system call
	and stores any error code returned by the system call in errno if an error occurs

#define _GNU_SOURCE         /* See feature_test_macros(7) */
#include <unistd.h>
#include <sys/syscall.h>   /* For SYS_xxx definitions */

long syscall(long number, ...);




$ vi glibc-2.30/sysdeps/unix/sysv/linux/x86_64/syscall.S
