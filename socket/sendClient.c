#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 2000

int main()
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

	send(sockfd, "send", strlen("send"), 0);

	while(read(STDIN_FILENO, buf, BUFFER_SIZE) > 0) {
		send(sockfd, buf, strlen(buf), 0);
		memset(buf, 0,BUFFER_SIZE);
	}

    printf("NO DATA\n");
    
    close(sockfd);
    exit(0);
}
