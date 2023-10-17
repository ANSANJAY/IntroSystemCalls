**Passing Parameters to System Calls**
- **Explain the technical concept**:
  - System calls, similar to regular function calls, can require parameters to operate. However, the way they handle parameters is distinct.
  - In typical function calls in C, arguments are pushed onto the stack. But when making a system call, you're transitioning from user space to kernel space. Directly passing parameters using the user space stack to the kernel can be unsafe.
  - Instead of using the stack, system calls utilize CPU registers to pass parameters. Before a system call is triggered, the necessary parameters are loaded into specific registers. Post the system call instruction, the kernel fetches these parameters from the registers and places them on its stack, allowing the system call service routine to access them.
  - This approach varies across architectures. For instance:
    - **x86**: 
      - Syscall number: `%eax`
      - Arguments: `%ebx, %ecx, %edx, %esi, %edi, %ebp`
      - Transition instruction: `int $0x80`
      - Return value: `%eax`
    - **x86_64**:
      - Syscall number: `rax`
      - Arguments: `rdi, rsi, rdx, rcx, r8, r9`
      - Transition instruction: `syscall`
      - Return value: `rax`

- **Curious Questions**:
  - **Why is it not safe to directly pass parameters using the user stack when making a system call?**
    - Using the user space stack directly poses a security risk as malicious programs could manipulate or misuse this data, leading to potential exploits or system instability.
  - **Why does the specific register for holding the syscall number or arguments change between different architectures like x86 and x86_64?**
    - Different architectures have distinct designs, register sets, and conventions. As architectures evolved (e.g., from x86 to x86_64), more registers became available and conventions adapted to make better use of the hardware.

- **Explain the concept in simple words**:
  - Imagine going through a security checkpoint at an airport 🛃✈️. You can't directly hand over your items to the person behind the X-ray machine. Instead, you place your items into bins (akin to CPU registers). Once you pass the checkpoint, the security personnel (akin to the kernel) takes these bins, inspects the items (reads the parameters), and then proceeds accordingly. Different airports (architectures) might have different procedures or specific bins for certain items, just as different architectures use distinct registers.