#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    FILE *read_fp;
    char buffer[BUFSIZ + 1];
    int char_read;

    memset(buffer, '\0', BUFSIZ + 1);
    read_fp = popen("uname -a", "r");
    if(read_fp != NULL) {
        char_read = fread(buffer, sizeof(char), BUFSIZ, read_fp); 
        if(char_read > 0) {
            printf("output was :- \n%s\n", buffer); 
        }
        pclose(read_fp);
        exit(EXIT_SUCCESS);
    }
    exit(EXIT_FAILURE);

}

