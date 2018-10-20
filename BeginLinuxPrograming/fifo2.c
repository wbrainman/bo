#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <limits.h>

#define FIFO_NAME "./my_fifo"
#define BUFFER_SIZE PIPE_BUF

int main(int argc, char *argv[])
{
    int res;
    int open_mode = O_RDONLY;
    int pipe_fd;
    int bytes_send;
    char buf[BUFFER_SIZE + 1];

    memset(buf, '\0', sizeof(buf)); 

    printf("Process %d open FIFO O_RDONLY\n", getpid());
    pipe_fd = open(FIFO_NAME, open_mode);
    printf("Process %d result %d\n", getpid(), pipe_fd);

    if(pipe_fd != -1) {
        do{
            res = read(pipe_fd, buf, BUFFER_SIZE); 
            bytes_send += res;
        }while(res > 0);

        (void)close(pipe_fd);
    }
    else {
        exit(EXIT_FAILURE);
    }

    printf("Process %d finish %d bytes readed\n", getpid(), bytes_send);

    exit(EXIT_SUCCESS);

}
