#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    int res = mkfifo("./my_fifo", 0777);
    perror(""); 
    if(res == 0) {
        printf("FIFO created\n"); 
    }
    exit(EXIT_SUCCESS);


}


