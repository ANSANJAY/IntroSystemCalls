**Return value of system calls** 📞
---

**1. Explain the technical concept:**
- System calls in Linux are interfaces through which user-space applications can request services from the kernel.
- The return value of these system calls is of type `long`.
  - ✅ If the system call completes successfully, it returns a value of `0` or a positive number.
  - ❌ If there's an error during the system call execution, it returns a negative value. This negative value represents the negation of an error code.
- The error code represents specific error conditions (like `ENOMEM`, `EIO`, `EPERM`, etc.).
- Although these error codes originate from the kernel, the kernel doesn't set the `errno` variable in user space directly.
- Library functions (wrappers) provided by glibc or another C library, wrap the actual system calls.
  - These wrappers inspect the returned value:
    - If it's negative, they set the user space's `errno` variable to the positive version of the error code and generally return `-1` to the calling program.

**2. Curious questions:**
- *What types of values can a system call return in Linux?*
  - **Answer**: A system call can return a positive value (including zero) indicating success, or a negative value indicating an error.

- *If a system call returns the value `-EIO`, what does this signify?*
  - **Answer**: The return value `-EIO` indicates an Input/Output error. The wrapper routine would set `errno` to the positive value of `EIO`.

- *Why doesn't the Linux kernel set the `errno` variable directly?*
  - **Answer**: The kernel operates in a different memory space than user applications. `errno` is a user-space concept, so the kernel doesn't have direct access to it. Instead, wrapper functions in the C library handle setting `errno` based on the kernel's system call return value.

**3. Explain the concept in simple words:**
- Imagine making a phone call (system call). After you finish talking, the person on the other end can either give you a thumbs up (positive value) meaning all is good, or a thumbs down (negative value) indicating there was a problem.
- If it's a thumbs down, they also whisper a reason in a secret code (negative error code).
- Now, you have a translator (the wrapper function) who listens to this code and writes down the reason in simple words (sets `errno`) for you to understand.

**Code section**:
The conceptual flow when a user-space program uses a system call wrapper might look something like this:

```c
int open_wrapper(const char *path, int flags) {
    long result = syscall_open(path, flags);  // Actual system call

    if (result < 0) {
        errno = -result;  // Set errno based on negated error code
        return -1;       // Standard error return for many syscalls
    }

    return result;  // Return actual result (e.g., file descriptor)
}
```
This code is a simplified representation and doesn't represent the actual implementation of the `open` syscall or its wrapper.
