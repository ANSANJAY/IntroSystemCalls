**What happens when we use a system call number which is not implemented?** 🚫📞
---

**1. Explain the technical concept:**
- System calls are interfaces through which user programs interact with the kernel. Each system call is identified by a unique number.
- The Linux kernel maintains a table of system calls, known as the system call table. This table maps system call numbers to their corresponding function implementations.
- When a system call is invoked using its number, the kernel checks the system call table to find the associated function and execute it.
- If the system call number used is not in this table (i.e., it's not implemented), the kernel does not have an associated function to run.
- In such cases, the kernel returns a specific error code: `-ENOSYS`, which stands for "Function not implemented".

**2. Curious questions:**
- *What does the kernel return when a system call number is not found in the system call table?*
  - **Answer**: The kernel returns the error code `-ENOSYS`, indicating that the function is not implemented.

- *Why does the kernel not just crash or halt when an unimplemented system call is invoked?*
  - **Answer**: Returning an error code provides a graceful way to handle such scenarios. It allows the calling program to detect the error and potentially handle it or notify the user, rather than causing an abrupt crash or unpredictable behavior.

**3. Explain the concept in simple words:**
- Imagine you're at a vending machine 🥫. Each button on the machine has a unique number, and pressing a button gives you a specific snack. If you press a button that doesn't correspond to any snack in the machine, instead of the machine breaking or doing nothing, it displays an error message "Item not available" 🚫. Similarly, when you use a system call number not implemented in the kernel, it doesn't crash but instead returns an error saying "Function not implemented".