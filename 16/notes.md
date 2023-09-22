How a system call is executed in other architecture?
---------------------------------------------------

You can find the information from man page $ man 2 syscall

       arch/ABI    instruction           syscall #  retval  error    Notes
       ────────────────────────────────────────────────────────────────────
       alpha       callsys               v0         a0      a3       [1]
       arc         trap0                 r8         r0      -
       arm/OABI    swi NR                -          a1      -        [2]
       arm/EABI    swi 0x0               r7         r0      -
       arm64       svc #0                x8         x0      -
       blackfin    excpt 0x0             P0         R0      -
       i386        int $0x80             eax        eax     -
       ia64        break 0x100000        r15        r8      r10      [1]
       m68k        trap #0               d0         d0      -
       microblaze  brki r14,8            r12        r3      -
       mips        syscall               v0         v0      a3       [1]
       nios2       trap                  r2         r2      r7
       parisc      ble 0x100(%sr2, %r0)  r20        r28     -
       powerpc     sc                    r0         r3      r0       [1]
       s390        svc 0                 r1         r2      -        [3]
       s390x       svc 0                 r1         r2      -        [3]
       superh      trap #0x17            r3         r0      -        [4]
       sparc/32    t 0x10                g1         o0      psr/csr  [1]
       sparc/64    t 0x6d                g1         o0      psr/csr  [1]
       tile        swint1                R10        R00     R01      [1]
       x86-64      syscall               rax        rax     -        [5]
       x32         syscall               rax        rax     -        [5]



