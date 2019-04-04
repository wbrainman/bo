#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/prctl.h>
#include <unistd.h>
 
#undef _POSIX_SOURCE
#include <sys/capability.h>
#include "libcap-2.25/libcap/libcap.h"
 
extern int errno;
  
void whoami(void)
{
	printf("uid=%i  euid=%i  gid=%i\n", getuid(), geteuid(), getgid());
}
 
void listCaps()
{
	cap_t caps = cap_get_proc();
	ssize_t y = 0;
	printf("The process %d was give capabilities %s\n",(int) getpid(), cap_to_text(caps, &y));
	fflush(0);
	cap_free(caps);
}
  
#if 0
int main(int argc, char **argv)
{

	int stat;
	whoami();
	stat = setuid(geteuid());
	pid_t parentPid = getpid();
 
	if(!parentPid)
	return 1;
	cap_t caps = cap_init();
 
	cap_value_t capList[5] ={ CAP_NET_RAW, CAP_NET_BIND_SERVICE , CAP_SETUID, CAP_SETGID,CAP_SETPCAP } ;
	unsigned num_caps = 5;
	cap_set_flag(caps, CAP_EFFECTIVE, num_caps, capList, CAP_SET);
	cap_set_flag(caps, CAP_INHERITABLE, num_caps, capList, CAP_SET);
	cap_set_flag(caps, CAP_PERMITTED, num_caps, capList, CAP_SET);

    printf("caps>head.pid = %d, version = %x\n", caps->head.pid, caps->head.version);

	if (cap_set_proc(caps)) {
		perror("capset()");
 
		return EXIT_FAILURE;
	}
	listCaps();
 
	printf("dropping caps\n");
	cap_clear(caps);  // resetting caps storage
 
	if (cap_set_proc(caps)) {
		perror("capset()");
		return EXIT_FAILURE;
	}
	listCaps();
 
	cap_free(caps);

	return 0;

}

#endif
#if 1
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

int main()
{
    pid_t pid;

    pid = fork();

    if(pid == 0) {
        //setuid(1000);
        //setgid(1000);
        //printf("in child pid = %d, uid = %d, gid = %d\n", getpid(),getuid(), getgid());
        execve("./main", NULL, NULL);
    }
    else {
        printf("in father pid = %d, child pid = %d, uid = %d, gid = %d\n", getpid(), pid, getuid(), getgid());
        //sleep(20);
    
    }

    return 0;
}
#endif
