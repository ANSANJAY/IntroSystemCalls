CPL
------------

This is the privilege of the currently executing code. Last two bits of CS register are considered as CPL.

Inter-segment calls, jumps, external interrupts, exceptions, task switching etc. operations can change the CS register contents thus, the privilege of currently executing code.

CS --- Code segment
