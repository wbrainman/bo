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
#include <pthread.h>
#include <serverRecv.h>
#include <serverSend.h>


#define BUFFER_SIZE 2000
#define MAX_INTERFACE 16

static struct sockaddr_in*  get_if_info(int fd);
static void  show_if_info(int fd, int if_num, struct ifreq* pbuf);
static void  get_if_status(unsigned int flag);


struct ifreq buf[MAX_INTERFACE];


static struct sockaddr_in*  get_if_info(int fd)
{
    int if_num = 0;
    struct ifconf ifc;
    struct ifreq ifr;
    
    ifc.ifc_len = sizeof(buf);
    ifc.ifc_buf = (caddr_t)buf;

    if(ioctl(fd, SIOCGIFCONF, (char*)&ifc)) {
        perror("get if config"); 
    }

    if_num = ifc.ifc_len/sizeof(struct ifreq);

    printf("*************************************************************\n");
    printf("interface num = %d\n",if_num);

    show_if_info(fd, if_num, buf);

    while(if_num --) {

        if(ioctl(fd, SIOCGIFADDR, &buf[if_num]) < 0) { 
            perror("ioctl");
        }

        if(htonl(INADDR_LOOPBACK) == ((struct sockaddr_in*)&(buf[if_num].ifr_addr))->sin_addr.s_addr) {
            continue; 
        }

        /*get network interface address*/
        printf("###################################\n");
        printf("get network interface address\n");
        printf("ip type: %d\n\n", ((struct sockaddr_in*)&buf[if_num].ifr_addr)->sin_family);
        printf("ip addr: %s\n\n", inet_ntoa(((struct sockaddr_in*)&(buf[if_num].ifr_addr))->sin_addr));
        printf("###################################\n");

        return (struct sockaddr_in*)&(buf[if_num].ifr_addr);
    }

}

static void  get_if_status(unsigned int flag)
{
    if(flag & IFF_UP) {
        printf("is up\n");
    }

    if(flag & IFF_BROADCAST) {
        printf("is broadcast\n");
    }

    if(flag & IFF_LOOPBACK) {
        printf("is loop back\n");
    }

    if(flag & IFF_POINTOPOINT) {
        printf("is point to point\n");
    }

    if(flag & IFF_RUNNING) {
        printf("is running\n");
    }

    if(flag & IFF_PROMISC) {
        printf("is promisc\n");
    }
}

static void  show_if_info(int fd, int if_num, struct ifreq* pbuf)
{
    while(if_num --) {

        printf("net dev %d name = %s\n",if_num, pbuf[if_num].ifr_name);

        if(ioctl(fd, SIOCGIFADDR, &pbuf[if_num]) < 0) { 
            perror("ioctl");
        }
        /*get network interface status*/
        get_if_status(pbuf[if_num].ifr_flags);

        /*get network interface address*/
        printf("ip type: %d\n", ((struct sockaddr_in*)&pbuf[if_num].ifr_addr)->sin_family);
        printf("ip addr: %s\n", inet_ntoa(((struct sockaddr_in*)&(pbuf[if_num].ifr_addr))->sin_addr));
    }
    printf("*************************************************************\n");
    printf("\n\n");

}

int main()
{
    int server_sockfd, connect_fd;
    int send_fd, recv_fd;
	struct sockaddr_in *pServer_addr;
	struct sockaddr_in client_address;
    int server_len = sizeof(struct sockaddr_in);
    int client_len = sizeof(struct sockaddr_in);

	char data[BUFFER_SIZE] = {0};


    int res;
    pthread_t thread_server_recv;
    pthread_t thread_server_send;

    server_sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    pServer_addr = get_if_info(server_sockfd);
	pServer_addr->sin_port = htons(8000);
    client_len = sizeof(client_address);

#if 0
	struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htonl(8000);
    printf("AAA	addr: %s\n",inet_ntoa(server_addr.sin_addr));
#endif



    bind(server_sockfd, (struct sockaddr *)pServer_addr, server_len);

    listen(server_sockfd, 5);

    while(1) {
        printf("\n");
        printf("*************************************************************\n");
        printf("server waiting\n");
        connect_fd = accept(server_sockfd, (struct sockaddr *)&client_address, &client_len);
		printf("client info:\n");
		printf("	type: %d\n",client_address.sin_family);
		printf("	port: %d\n",ntohs(client_address.sin_port));
		printf("	addr: %s\n",inet_ntoa(client_address.sin_addr));
		printf("\n");

        if(recv(connect_fd, data, BUFFER_SIZE, 0) > 0) {
#if 1
            if(0 == strcmp(data, "recv")) {
				send_fd = connect_fd;
                printf("we can send now, sockfd = %d\n",send_fd);
                res = pthread_create(&thread_server_recv, NULL, server_send, (void*)(&send_fd)); 
                if(res != 0) {
                    perror("Thread server recv creat failed"); 
                    exit(EXIT_FAILURE);
                }
            }
//#else

            if(0 == strcmp(data, "send")) {
				recv_fd = connect_fd;
                printf("we can recv now, sockfd = %d\n",recv_fd);
                res = pthread_create(&thread_server_send, NULL, server_recv, (void*)(&recv_fd)); 
                if(res != 0) {
                    perror("Thread server send creat failed"); 
                    exit(EXIT_FAILURE);
                }
            }
#endif

        }

    }

}

















