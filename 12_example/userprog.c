#include <stdio.h>
#include <sys/auxv.h>

int main()
{
	unsigned long sysinfo = getauxval(AT_SYSINFO);
	unsigned long syscall_num = 1;  // 1 is system call number for exit
	long exit_status = 42;

	asm ("movl %0, %%eax\n"
			"movl %1, %%ebx\n"
			"call *%2"
			:
			:"m" (syscall_num), "m" (exit_status), "m" (sysinfo)
			:"eax", "ebx");

	return 0;
}
