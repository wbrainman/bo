#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int data_processed;
    int file_pipes[2];
    const char some_data[] = "123";
    char buffer[BUFSIZ + 1];
    pid_t fork_result;

    memset(buffer, '\0', BUFSIZ + 1);
    if(pipe(file_pipes) == 0) {
        fork_result = fork(); 
        if( -1 == fork_result) {
            fprintf(stderr, "fork failure"); 
            exit(EXIT_FAILURE);
        }
        if(0 == fork_result) {
            data_processed = read(file_pipes[0], buffer, BUFSIZ); 
            printf("Read %d bytes, %s\n", data_processed, buffer);
        }
        else {
            data_processed = write(file_pipes[1], some_data, sizeof(some_data)); 
            printf("Write %d bytes\n\n", data_processed);
        }
    }

    exit(EXIT_SUCCESS);

}

