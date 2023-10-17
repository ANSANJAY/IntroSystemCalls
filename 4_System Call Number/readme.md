**System Call Number**
- **Explain the technical concept**:
  - A **System Call Number** is a unique identifier associated with each system call. It acts as an index, allowing the kernel to know which specific system call a userspace application is requesting. 
  - These system call numbers can vary based on the architecture. For instance, while the `exit()` system call might be identified by number 60 on an x86_64 architecture, it might be identified by the number 1 on an x86 architecture.
  
- **Curious Questions**:
  - **Why can't we use the system call's name, like "exit", as an identifier instead of a number?**
    - Using numbers is more efficient for the computer. It's quicker to look up an index in a table using a number than to match a string name. Plus, numbers occupy less memory and reduce the chance of ambiguity.
  - **What could be the implication if two system calls were mistakenly given the same number on an architecture?**
    - It would lead to unpredictable behavior, as the kernel wouldn't be able to differentiate between the two system calls based on their number alone.

**System Call Table**
- **Explain the technical concept**:
  - The **System Call Table** is a data structure maintained by the kernel. It maps system call numbers to their respective handlers (the actual functions in the kernel that carry out the system call). When a system call is made, the kernel references this table to determine which function to execute based on the provided system call number.
  
- **Curious Questions**:
  - **What would happen if an entry in the System Call Table gets corrupted?**
    - If an entry in the table is corrupted, the corresponding system call might malfunction or cause unexpected behavior. This could lead to application errors, system instability, or security vulnerabilities.
  - **Why is the System Call Table architecture-specific?**
    - Different architectures can have variations in their instruction sets, hardware capabilities, and conventions. Thus, the system calls (and their numbers) may differ or be implemented differently across architectures.

## Location of System Call Table
------------------------------

For x86: arch/x86/entry/syscalls/syscall_32.tbl
x86_64:  arch/x86/entry/syscalls/syscall_64.tbl
arm:	 arch/arm/tools/syscall.tbl

- **Explain the concept in simple words**:
  - Picture the System Call Table as a telephone directory 📖☎️. When you want to call someone (make a system call), you don't dial their name; you look up their unique phone number (system call number) and dial that. The phone system (kernel) then connects your call based on this number. Just as different countries might have different phone directories, different computer architectures have different System Call Tables.




