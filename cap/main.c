
#include "cap.h"
#include "setEther.h"


int main()
{
    pid_t pid;
    pid = fork();
    int ret = 0;

    if(pid == 0) {
#if 0
        showCap(getpid());
        ret = prctl(PR_SET_KEEPCAPS, 1);
        if (ret) {
            perror("prctl");
            return -1;
       }
        showCap(getpid());
#endif
        char* pFile = "./test";
        clearFileCap(pFile);
        showFileCap(pFile);
        setFileCap(pFile);
        showFileCap(pFile);
        setgid(1000);
        setuid(1000);


        execve("./test", NULL, NULL);
    }
    else {
        //printf("in father pid = %d, child pid = %d, uid = %d, gid = %d\n", getpid(), pid, getuid(), getgid());
    
    }

    return 0;
}
