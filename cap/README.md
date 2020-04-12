# capability
##    Past and current implementation
       A full implementation of capabilities requires that:

       1. For all privileged operations, the kernel must check whether the
          thread has the required capability in its effective set.

       2. The kernel must provide system calls allowing a thread's
          capability sets to be changed and retrieved.

       3. The filesystem must support attaching capabilities to an
          executable file, so that a process gains those capabilities when
          the file is executed.

### Permitted
  Permitted是effective和inheritable的超集。
