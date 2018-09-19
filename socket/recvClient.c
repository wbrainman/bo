
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "recvClient.h"



#define BUFFER_SIZE 2000

void *thread_recv(void *arg)
{
    int sockfd;
    int len;
    struct sockaddr_in address;
    int result;
    char buf[BUFFER_SIZE] = {0};

    printf("thread_recv\n");

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("192.168.97.136");
    //address.sin_addr.s_addr = inet_addr("192.168.97.66");
    address.sin_port = htons(9734);

    len = sizeof(address);


    result = connect(sockfd, (struct sockaddr *)&address, len);
    if(result == -1) {
        perror("oops: client1");
        exit(1);
    }

	send(sockfd, "recv", strlen("recv"), 0);
    perror("client recv declare:");

    while (0 < recv(sockfd, buf, BUFFER_SIZE, 0)) {
        printf("client recv data : %s\n", buf);
        memset((void*)buf, 0, BUFFER_SIZE);
    }

    printf("NO DATA\n");
    
    close(sockfd);
    exit(0);
}
