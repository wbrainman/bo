
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/prctl.h>
#include <unistd.h>
 
#undef _POSIX_SOURCE
#include <sys/capability.h>
#include "libcap-2.25/libcap/libcap.h"

extern void showCap(pid_t pid);

extern void setCap(pid_t pid);
