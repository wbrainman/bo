#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>


#define BUFFER_SIZE 2000
int main()
{

    int server_sockfd, client_sockfd;
    int server_len, client_len;
	struct sockaddr_in server_address;
	struct sockaddr_in client_address;

	char buf[BUFFER_SIZE] = {0};
	unsigned int n;

#if 0	
	{
		struct netent *netInfo;	
		int addr;

		netInfo = getnetent();
#if 0	
        char myname[256];
		const char *pName;
        gethostname(myname, 255);
		pName = myname;
		printf("get host name: %s\n",pName);
		netInfo = getnetbyname(pName);
#endif

		if(!netInfo) {
			fprintf(stderr,"get netInfo error\n");	
			exit(1);
		}

		printf("get net info:\n");
		printf("	network name: %s\n",netInfo->n_name);

		while(*(netInfo->n_aliases)) {
			printf("	network alias name: %s\n",*(netInfo->n_aliases));
		}

		printf("	address type: %d\n",netInfo->n_addrtype);
		addr = ntohl(netInfo->n_net);
		printf("	addr: %s\n",inet_ntoa(*(struct in_addr *)&addr));
	
	}
#endif

    //2. Remove any old sockets and create an unnamed socket for the server:

    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

    {
        #include <net/if.h>
        #include <sys/ioctl.h>
        struct ifreq ifr;
        strcpy(ifr.ifr_name, "eth0");
        if(ioctl(server_sockfd, SIOCGIFADDR, &ifr) < 0)
            perror("ioctl");
        printf("%s\n", inet_ntoa(((struct sockaddr_in*)&(ifr.ifr_addr))->sin_addr));
    
    }

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

















