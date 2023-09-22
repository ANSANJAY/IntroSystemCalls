#include <stdio.h>

int main(int argc, char *argv[])
{
	unsigned long syscall_num = 1;  // 1 is system call number for exit
	long exit_status = 42;

	asm ("movl %0, %%eax\n"
			"movl %1, %%ebx\n"
			"int $0x80"
			:
			:"m" (syscall_num), "m" (exit_status)
			:"eax", "ebx");
	return 0;
}

