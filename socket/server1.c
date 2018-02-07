#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <net/if.h>
#include <sys/ioctl.h>


#define BUFFER_SIZE 2000
#define MAX_INTERFACE 16

static char*  get_if_info(int fd)
{
    int if_num = 0;
    struct ifreq buf[MAX_INTERFACE];
    struct ifconf ifc;
    struct ifreq ifr;
    
    ifc.ifc_len = sizeof(buf);
    ifc.ifc_buf = (caddr_t)buf;

    if(ioctl(fd, SIOCGIFCONF, (char*)&ifc)) {
        perror("get if config"); 
    }

    if_num = ifc.ifc_len/sizeof(struct ifreq);

    printf("interface num = %d\n\n",if_num);

    while(if_num --) {

        printf("net dev %d name = %s\n",if_num, buf[if_num].ifr_name);

        if(ioctl(fd, SIOCGIFADDR, &buf[if_num]) < 0) { 
            perror("ioctl");
        }
        printf("%s\n\n", inet_ntoa(((struct sockaddr_in*)&(buf[if_num].ifr_addr))->sin_addr));
    }


}


int main()
{

    int server_sockfd, client_sockfd;
    int server_len, client_len;
	struct sockaddr_in server_address;
	struct sockaddr_in client_address;

	char buf[BUFFER_SIZE] = {0};
	unsigned int n;

    //2. Remove any old sockets and create an unnamed socket for the server:

    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

    //printf("if num %d\n",get_if_info(server_sockfd);
    get_if_info(server_sockfd);

    

    //3. Name the socket:
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = inet_addr("192.168.0.106");
	server_address.sin_port = htons(9734);

    server_len = sizeof(server_address);

    bind(server_sockfd, (struct sockaddr *)&server_address, server_len);

    //4. Create a connection queue and wait for clients:
    listen(server_sockfd, 5);

    while(1) {

        printf("server waiting\n");

        //5. Accept a connection:
        client_len = sizeof(client_address);
        client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, &client_len);
		printf("client info:\n");
		printf("	type: %d\n",client_address.sin_family);
		printf("	port: %d\n",ntohs(client_address.sin_port));
		printf("	addr: %s\n",inet_ntoa(client_address.sin_addr));

		if(fork() == 0) {
			while(n = read(STDIN_FILENO, buf, BUFFER_SIZE) > 0) {
					
				send(client_sockfd, buf, strlen(buf), 0);
				memset(buf, 0,BUFFER_SIZE);
			}
			close(client_sockfd);
		}
		else {
			close(client_sockfd);
		}

    }

}

















