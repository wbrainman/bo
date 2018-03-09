#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "serverSend.h"



#define BUFFER_SIZE 2000

void *server_send(void *arg)
{
    if(NULL == arg) {
        exit(EXIT_FAILURE);
    }

	char data[BUFFER_SIZE] = {0};
    int client_sockfd = *(int*)arg;
    int n = 0;

    while(n = read(STDIN_FILENO, data, BUFFER_SIZE) > 0) {
        send(client_sockfd, data, strlen(data), 0);
        memset(data, 0,BUFFER_SIZE);
    }

}
