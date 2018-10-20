#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void *thread_func(void *arg);

int main()
{
    int res;
    pthread_t a_thread;
    void* thread_result;

    res = pthread_create(&a_thread, NULL, thread_func, NULL);
    if(res != 0) {
        perror("thread create failed"); 
        exit(EXIT_FAILURE);
    }

    sleep(3);
    printf("Canceling thread\n");
    res = pthread_cancel(a_thread);
    if(res != 0) {
        perror("thread cancel failed"); 
        exit(EXIT_FAILURE);
    }

    printf("Waiting for thread to finish...\n");

    res = pthread_join(a_thread, &thread_result);
    if(res != 0) {
        perror("thread join failed"); 
        exit(EXIT_FAILURE);
    }
    printf("thread finished\n");
    exit(EXIT_SUCCESS);
}

void *thread_func(void *arg)
{
    int i, res;
    res = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    if(res != 0) {
        perror("set cancel state failed"); 
        exit(EXIT_FAILURE);
    }

    //res = pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
    res = pthread_setcanceltype(PTHREAD_CANCEL_ENABLE, NULL);
    if(res != 0) {
        perror("set cancel type failed"); 
        exit(EXIT_FAILURE);
    }

    printf("thread func is runing\n");
    for(i = 0; i < 10; i++) {
        printf("thread func is still runing %d\n",i);
        sleep(1);
    }
    pthread_exit(0);
}
