#include <stdio.h>
#include <sys/auxv.h>
#include <unistd.h>
#include <errno.h>

int main()
{
	unsigned long syscall_num = 41;  // 41 is system call number for dup
	unsigned int oldfd = 9; // i gave a wrong file descriptor
	unsigned int return_value = 0;

	return_value = syscall(syscall_num, oldfd);
	printf("errno:%d\n", errno);
	printf("Return value:%d\n", return_value);
	return 0;
}
