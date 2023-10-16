#include <stdio.h>
int main()
{
    int cpl;
    asm volatile("mov %%cs, %%eax"
                    :"=a"(cpl));
    cpl &= 0x03;
    printf("cpl:%02x\n", cpl);
    return 0;
}
