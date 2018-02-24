#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#include <recvClient.h>
#include <sendClient.h>

#define THREAD_NUM 2


int mian()
{
    int res;
    pthread_t t_recv;
    pthread_t t_send;

    res = pthread_create(&t_recv, NULL, thread_recv); 
    if(res != 0) {
        perror("Thread recv creat failed"); 
        exit(EXIT_FAILURE);
    }

    res = pthread_create(&t_recv, NULL, thread_send); 
    if(res != 0) {
        perror("Thread send creat failed"); 
        exit(EXIT_FAILURE);
    }

}

