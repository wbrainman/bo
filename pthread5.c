#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void *thread_func(void *arg);

char message[] = "Hello World";
int thread_finish = 0;

int main()
{
    int res;
    pthread_t a_thread;
    pthread_attr_t thread_attr;

    res = pthread_attr_init(&thread_attr);
    if(res != 0) {
        perror("attribute create failed"); 
        exit(EXIT_FAILURE);
    }

    res = pthread_attr_setdetachstate(&thread_attr, PTHREAD_CREATE_DETACHED);
    if(res != 0) {
        perror("set attribute failed"); 
        exit(EXIT_FAILURE);
    }

    res = pthread_create(&a_thread, &thread_attr, thread_func, (void*)message);
    if(res != 0) {
        perror("thread create failed"); 
        exit(EXIT_FAILURE);
    }

    (void)pthread_attr_destroy(&thread_attr);

    while(!thread_finish) {
        printf("Waiting for thread to finish...\n");
        sleep(1);
    }
}

void *thread_func(void *arg)
{
    printf("thread func is running, arg is  %s\n", (char*)arg);
    sleep(5);
    printf("set thread_finish = 1\n");
    thread_finish = 1;
    pthread_exit("Thank you for the cup time\n");


}
