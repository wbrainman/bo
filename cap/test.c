#include "cap.h"


int main (int argc, char** argv)
{
    int ret = 0;
    printf("in test\n");
    //setCap(getpid());	/*注释3*/

#if 1
    ret = prctl(PR_SET_KEEPCAPS, 1);
    if (ret) {
        perror("prctl");
        return -1;
   }
#endif

    printf("before set uid 1000\n");
    showCap(getpid());
    setuid(1000);
    setCap(getpid());	/*注释3*/
    printf("after set uid 1000\n");
    while (1) {
        sleep (10);
        showCap(getpid());
    }
    return 0;
}
