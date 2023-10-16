#include <linux/kernel.h>
#include <linux/module.h>
MODULE_LICENSE("GPL");
int init_module()
{
    int cpl;
    asm volatile("mov %%cs, %%eax"
            :"=a"(cpl));
    cpl &= 0x03;
    pr_info("cpl:%02x\n", cpl);
    return 0;
}
void cleanup_module()
{
}
