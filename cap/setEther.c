#include"setEther.h"

void setEtherStatus(const char *ethNum, int upDown)
{
    struct ifreq ifr;
    int sockfd = -1;
    int res = 0;

    if ((sockfd = socket(AF_INET6, SOCK_STREAM, 0)) < 0) {
        perror("Create socket fails!");
        return ;
    }

    strncpy(ifr.ifr_name, ethNum, IFNAMSIZ);
    if (ioctl(sockfd, SIOCGIFFLAGS, &ifr) < 0) {
        perror("ioctl SIOCGIFFLAGS fails!");
        close(sockfd);
        return ;
    }

    upDown ? (ifr.ifr_flags |= IFF_UP) : (ifr.ifr_flags &= ~IFF_UP);
    if ((res = ioctl(sockfd, SIOCSIFFLAGS, &ifr)) < 0) {
        perror("ioctl SIOCSIFFLAGS fails! ");
        close(sockfd);
        return ;
    }

    if (-1 != sockfd) {
        close(sockfd);
    }
}
