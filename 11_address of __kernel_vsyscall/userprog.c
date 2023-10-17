#include <stdio.h>
#include <sys/auxv.h>

int main()
{
	printf("AT_BASE:          %lx\n", getauxval(AT_BASE));
	printf("AT_BASE_PLATFORM: %lx\n", getauxval(AT_BASE_PLATFORM));
	printf("AT_CLKTCK:        %lx\n", getauxval(AT_CLKTCK));
	printf("AT_DCACHEBSIZE:   %lx\n", getauxval(AT_DCACHEBSIZE));
	printf("AT_EGID:          %lx\n", getauxval(AT_EGID));
	printf("AT_ENTRY:         %lx\n", getauxval(AT_ENTRY));
	printf("AT_EUID:          %lx\n", getauxval(AT_EUID));
	printf("AT_EXECFD:        %lx\n", getauxval(AT_EXECFD));
	printf("AT_EXECFN:        %lx\n", getauxval(AT_EXECFN));
	printf("AT_FLAGS:         %lx\n", getauxval(AT_FLAGS));
	printf("AT_FPUCW:         %lx\n", getauxval(AT_FPUCW));
	printf("AT_GID:           %lx\n", getauxval(AT_GID));
	printf("AT_HWCAP:         %lx\n", getauxval(AT_HWCAP));
	printf("AT_HWCAP2:        %lx\n", getauxval(AT_HWCAP2));
	printf("AT_ICACHEBSIZE:   %lx\n", getauxval(AT_ICACHEBSIZE));
	printf("AT_PHDR:          %lx\n", getauxval(AT_PHDR));
	printf("AT_PHENT:         %lx\n", getauxval(AT_PHENT));
	printf("AT_PHNUM:         %lx\n", getauxval(AT_PHNUM));
	printf("AT_PLATFORM:      %lx\n", getauxval(AT_PLATFORM));
	printf("AT_RANDOM:        %lx\n", getauxval(AT_RANDOM));
	printf("AT_SECURE:        %lx\n", getauxval(AT_SECURE));
	printf("AT_SYSINFO:       %lx\n", getauxval(AT_SYSINFO));
	printf("AT_SYSINFO_EHDR:  %lx\n", getauxval(AT_SYSINFO_EHDR));
	printf("AT_UCACHEBSIZE:   %lx\n", getauxval(AT_UCACHEBSIZE));
	printf("AT_UID:           %lx\n", getauxval(AT_UID));

	return 0;
}
