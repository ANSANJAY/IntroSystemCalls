ldd ./prog

linux-vdso.so.1 (0x00007ffce147a000)
libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f6ef9e8e000)
/lib64/ld-linux-x86-64.so.2 (0x00007f6efa481000)

sudo find / -name 'linux-vdso.so*'

Will do not give any results.

It's a virtual shared object that doesn't have any physical file on the disk

it's a part of the kernel that's exported into every program's address space when it's loaded.


