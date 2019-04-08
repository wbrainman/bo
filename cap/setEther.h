
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/if.h>

extern void setEtherStatus(const char *ethNum, int upDown);
