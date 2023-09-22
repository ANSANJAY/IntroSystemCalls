What is System Call
--------------------

System calls provide userspace processes a way to request services from the kernel.

	or

It is a way of requesting the kernel to do something on your behalf

What kind of services?
----------------------
Services which are managed by operating system like storage, memory, network, process management etc.

Examples of Kernel Service
1. Write/read file
2. Listen for connections on a socket
3. Create/Delete directory
4. creating and executing new processes,

On Unix systems, the C library provides wrapper around these system calls
