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
#define TEN_MEG (1024*1024*10)

int main()
{
    int res;
    int open_mode = O_WRONLY;
    int i;
    int pipe_fd;
    int bytes_send;
    char buf[BUFFER_SIZE + 1];

    if(access(FIFO_NAME, F_OK) == -1) {
      res = mkfifo(FIFO_NAME, 0777);
      if(-1 ==res) {
        printf("mkfifo error\n");
        perror("");
        exit(EXIT_FAILURE);
      }
    }

    printf("Process %d open FIFO O_WRONLY\n", getpid());
    pipe_fd = open(FIFO_NAME, open_mode);
    printf("Process %d result %d\n", getpid(), pipe_fd);
    if(pipe_fd != -1) {
        while(bytes_send < TEN_MEG) {
            res = write(pipe_fd, buf, BUFFER_SIZE); 
            if(-1 == res) {
                fprintf(stderr, "wirte error on pipe"); 
                exit(EXIT_FAILURE);
            }
            bytes_send += res;
        }

        (void)close(pipe_fd);
    }
    else {
        exit(EXIT_FAILURE);
    }

    printf("Process %d finish\n", getpid());

    exit(EXIT_SUCCESS);

}
