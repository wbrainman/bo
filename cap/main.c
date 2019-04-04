#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/prctl.h>

#undef _POSIX_SOURCE
#include <sys/capability.h>
#include "libcap-2.25/libcap/libcap.h"

void showCap(pid_t pid)
{
     struct __user_cap_header_struct cap_header_data;
     cap_user_header_t cap_header = &cap_header_data;

     struct __user_cap_data_struct cap_data_data;
     cap_user_data_t cap_data = &cap_data_data;

     cap_header->pid = pid;
     cap_header->version = _LINUX_CAPABILITY_VERSION_1;

     if (capget(cap_header, cap_data) < 0) {
         perror("Failed capget");
         exit(1);
     }
     printf("pid %d, Cap data 0x%x, 0x%x, 0x%x\n", pid,cap_data->effective, cap_data->permitted, cap_data->inheritable);
}

void setCap(pid_t pid)
{
     struct __user_cap_header_struct cap_header_data;
     cap_user_header_t cap_header = &cap_header_data;

     struct __user_cap_data_struct cap_data_data;
     cap_user_data_t cap_data = &cap_data_data;

     cap_header->pid = pid;
     cap_header->version = _LINUX_CAPABILITY_VERSION_1;

     if (capget(cap_header, cap_data) < 0) {
         perror("Failed capget");
         exit(1);
     }

    cap_data->effective &= ~(1 << CAP_NET_ADMIN);
    cap_data->permitted &= ~(1 << CAP_NET_ADMIN);
    cap_data->inheritable &= ~(1 << CAP_NET_ADMIN);

    printf("setCap pid %d, Cap data 0x%x, 0x%x, 0x%x\n", pid,cap_data->effective, cap_data->permitted, cap_data->inheritable);

     if (capset(cap_header, cap_data) < 0) {
         perror("Failed capset");
         exit(1);
     }
}

int main (int argc, char** argv) {
    printf("in main");
    setCap(getpid());
    while (1) {
        sleep (10);
        showCap(getpid());
    }
    return 0;
}
