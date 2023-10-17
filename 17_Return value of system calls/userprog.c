#include <stdio.h>
#include <sys/auxv.h>
#include <errno.h>

int main()
{
	unsigned long sysinfo = getauxval(AT_SYSINFO);
	unsigned long syscall_num = 41;  // 41 is system call number for dup
	unsigned int oldfd = 9; // i gave a wrong file descriptor
	unsigned int return_value = 0;

	asm volatile ("movl %1, %%eax\n"
			"movl %2, %%ebx\n"
			"call *%3\n"
			"movl %%eax, %0"
			: "=r"(return_value)
			:"m" (syscall_num), "m" (oldfd), "m" (sysinfo)
			:"eax", "ebx");
	printf("Errno:%d\n", errno);
	printf("Return value:%d\n", return_value);
	return 0;
}
