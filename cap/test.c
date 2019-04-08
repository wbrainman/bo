#include "cap.h"
#include "setEther.h"


int main (int argc, char** argv)
{
    printf("in test\n");

    showCap(getpid());
    setEtherStatus("eth0", 1);
    return 0;
}
