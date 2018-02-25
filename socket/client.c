#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#include <recvClient.h>
#include <sendClient.h>

#define THREAD_NUM 2


int main()
{
    int res;
    pthread_t t_recv;
    pthread_t t_send;

	void *thread_result;

    res = pthread_create(&t_recv, NULL, thread_recv, NULL); 
    if(res != 0) {
        perror("Thread recv creat failed"); 
        exit(EXIT_FAILURE);
    }

    res = pthread_create(&t_recv, NULL, thread_send, NULL); 
    if(res != 0) {
        perror("Thread send creat failed"); 
        exit(EXIT_FAILURE);
    }

	res = pthread_join(t_recv, &thread_result);
    if(res != 0) {
        perror("Thread recv join failed"); 
        exit(EXIT_FAILURE);
    }

	res = pthread_join(t_send, &thread_result);
    if(res != 0) {
        perror("Thread send join failed"); 
        exit(EXIT_FAILURE);
    }

	printf("All done !!!\n");

}

