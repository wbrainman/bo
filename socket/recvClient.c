
#include "recvClient.h"



#define BUFFER_SIZE 2000

void *thread_recv(void *arg)
{
    int sockfd;
    int len;
    struct sockaddr_in address;
    int result;
    char buf[BUFFER_SIZE] = {0};

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("192.168.0.106");
    address.sin_port = htons(9734);

    len = sizeof(address);

    result = connect(sockfd, (struct sockaddr *)&address, len);
    if(result == -1) {
        perror("oops: client1");
        exit(1);
    }

	send(sockfd, "recv", strlen("recv"), 0);

    while ( 1 ) {
      if(0 < recv(sockfd, buf, BUFFER_SIZE, 0)) {
        printf("recv data : %s\n", buf);
        memset((void*)buf, 0, BUFFER_SIZE);
      }
    }

    printf("NO DATA\n");
    
    close(sockfd);
    exit(0);
}