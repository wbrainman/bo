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
    int sockfd = *(int*)arg;
    int n = 0;
	printf("server_send, sockfd = %d\n",sockfd);

    while((n = read(STDIN_FILENO, data, BUFFER_SIZE)) > 0) {
        printf("in server send n = %d\n",n);
        send(sockfd, data, strlen(data), 0);
        perror("in server send:");
        //memset(data, 0,BUFFER_SIZE);
    }

}
