**Difference between System Call and Function Call**
- **Explain the technical concept**:
  - A **System Call** is an interface that allows a user-space application to request specific services or operations from the kernel. This means that when a system call is made, the operation runs within the kernel's context, and the program transitions from user mode to kernel mode. Because kernel mode has more privileges, transitioning requires special instructions to ensure the integrity and security of the system.
  - A **Function Call**, on the other hand, is a basic programming concept where one section of the code (a function) is executed from another. This call happens within the same context and doesn't involve switching between modes or any interaction with the kernel directly.
  - System calls are identified by unique system call numbers, while function calls are determined by function addresses in memory.

- **Curious Questions**:
  - **Why is the transition to kernel mode necessary for system calls but not for function calls?**
    - The transition is necessary for system calls because they deal with privileged operations that need to be executed securely within the kernel. Function calls, however, operate within the confines of the program's own memory and don't require such privileges.
  - **What happens if an unauthorized program tries to directly execute a privileged operation without using a system call?**
    - The CPU's protection mechanisms will typically generate an exception, like a segmentation fault, and the offending program might be terminated.

- **Explain the concept in simple words**:
  - Think of a system call like asking a security guard to unlock a secure door for you 🚪🔐. You can't open it yourself because you don't have the key (privileged access). The guard checks your request, then unlocks and opens the door if it's appropriate. On the other hand, a function call is like opening an unlocked door inside your own house. You don't need anyone's permission, and you know exactly where the door leads.
