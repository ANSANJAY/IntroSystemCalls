#include <stdio.h>

int main(int argc, char *argv[])
{
	unsigned long syscall_number = 60;
	long exit_status = 12;

	asm ("movq %0, %%rax\n"
			"movq %1, %%rdi\n"
			"syscall"
			:
			:"m" (syscall_number), "m" (exit_status)
		    	:"rax", "rdi");
}
