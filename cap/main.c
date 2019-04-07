
#include "cap.h"

int main()
{
    pid_t pid;

    pid = fork();

    if(pid == 0) {
    	//setCap(getpid());	/*注释2*/
        execve("./test", NULL, NULL);
    }
    else {
        printf("in father pid = %d, child pid = %d, uid = %d, gid = %d\n", getpid(), pid, getuid(), getgid());
    	//setCap(pid); /*注释1*/
    
    }

    return 0;
}
