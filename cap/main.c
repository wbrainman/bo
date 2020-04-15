
#include "cap.h"
#include "setEther.h"
#include <unistd.h>


#if 0
int main()
{
    pid_t pid;
    pid = fork();
    int ret = 0;

    if(pid == 0) {
        printf("in child pid = %d, child pid = %d, uid = %d, gid = %d\n", getpid(), pid, getuid(), getgid());
        showCap(getpid());
        char* pFile = "./main";
        showFileCap(pFile);
#if 0
        showCap(getpid());
        ret = prctl(PR_SET_KEEPCAPS, 1);
        if (ret) {
            perror("prctl");
            return -1;
       }
        showCap(getpid());
        clearFileCap(pFile);
        setFileCap(pFile);
        showFileCap(pFile);
        setgid(1000);
        setuid(1000);
        execve("./test", NULL, NULL);
#endif
        pause();


    }
    else {
        printf("in father pid = %d, child pid = %d, uid = %d, gid = %d\n", getpid(), pid, getuid(), getgid());
        showCap(getpid());
    
    }

    return 0;
}
#endif



/* If a thread drops a capability from its permitted set, it can
 * never reacquire that capability unless it execve(2)s either a
 * set-user-ID-root program 
 */                             
int main()
{
    printf("pid = %d, id = %d, gid = %d\n", getpid(), getuid(), getgid());
    //showCapInHex(getpid());
    showCap(getpid());
    //setProcessCap(getpid());
    execve("./test", NULL, NULL);
    return 0;
}

