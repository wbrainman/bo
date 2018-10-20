#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int agrc, char* argv[])
{
    int data_processed;
    char buffer[BUFSIZ + 1];
    int file_descriptor;

    memset(buffer, '\0', BUFSIZ + 1);
    sscanf(argv[1], "%d", &file_descriptor);
    data_processed = read(file_descriptor, buffer, BUFSIZ);

    printf("%d - read %d bytes, %s\n", getpid(), data_processed, buffer);

    exit(EXIT_SUCCESS);

}

