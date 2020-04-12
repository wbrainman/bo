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
       如果一个trread从Permitted drop a capability，它将无法再得到那个capability。除非：
       - execve()一个set-user-ID-root program.
       - execve()一个file，此file带有这个capability.
### Inheritable
       - thrad的Inheritable是什么，execve()一个file后，Inheritable保持不变。
       - 如果file的Inheritable中有一个capability，那个execve()之后，thread的Permitted将得到这个capability.
   
