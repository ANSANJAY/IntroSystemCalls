#include <stdio.h>
#include <sys/auxv.h>

int main()
{
	unsigned long sysinfo = getauxval(AT_SYSINFO);
	unsigned long syscall_num = 4;  // 4 is system call number for write
	char buffer[] = "hello world";
        int buffer_length = sizeof(buffer);	

	asm ("movl %0, %%eax\n"
			"movl %1, %%ebx\n"
			"movl %2, %%ecx\n"
			"movl %3, %%edx\n"
			"call *%4"
			:
			:"m" (syscall_num), "i"(1), "r" (buffer), "m"(buffer_length), "m"(sysinfo)
			:"eax", "ebx", "ecx", "edx");

	return 0;
}
