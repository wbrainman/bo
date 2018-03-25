
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "serverRecv.h"



#define BUFFER_SIZE 2000

void *server_recv(void *arg)
{
    if(NULL == arg) {
        exit(EXIT_FAILURE);
    }

	char data[BUFFER_SIZE] = {0};
    int sockfd = *(int*)arg;
	printf("server_recv, sockfd = %d\n",sockfd);

    while (0 < recv(sockfd, data, BUFFER_SIZE, 0)) {
        printf("server recv data : %s\n", data);
        memset((void*)data, 0, BUFFER_SIZE);
    }


}
