strace and vdso
==================

When tracing systems calls with strace, system calls that are exported by the vDSO will not appear in the trace output.

You can capture calls to system calls which have been implemented via the vDSO by using ltrace instead of strace.
