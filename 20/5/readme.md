ldd ./prog

linux-vdso.so.1 (0x00007ffce147a000)
libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f6ef9e8e000)
/lib64/ld-linux-x86-64.so.2 (0x00007f6efa481000)

sudo find / -name 'linux-vdso.so*'

Will do not give any results.


