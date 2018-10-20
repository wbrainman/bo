#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void *thread_func(void *arg);

#define THREAD_MAX 6

int main()
{
    int res;
    pthread_t a_thread[THREAD_MAX];
    void *thread_result;
    int lots_threads = 0;

    for(lots_threads = 0; lots_threads < THREAD_MAX; lots_threads ++) {
        res = pthread_create(&(a_thread[lots_threads]), NULL, thread_func, (void*)&lots_threads);
        if(res != 0) {
            perror("thread create failed"); 
            exit(EXIT_FAILURE);
        }
//        sleep(1);
    }
    printf("Waiting for thread to finish...\n");


    for(lots_threads = THREAD_MAX - 1; lots_threads >= 0; lots_threads --) {
        res = pthread_join(a_thread[lots_threads], &thread_result);
        if(res == 0) {
            printf("picked up a thread\n");
        }
        else {
            perror("thread join failed"); 
        }
    }
    printf("all down\n");
    exit(EXIT_SUCCESS);

}


void *thread_func(void *arg)
{
    int my_num = *(int*)arg;
    int rand_num;
    printf("thread func is running, arg is  %d\n", my_num);
    rand_num = 1 + (int)(0.9*rand() / (RAND_MAX + 1.0));
//    printf("rand_num is %d\n",rand());
    //sleep(rand_num);
    printf("bye from  %d\n", my_num);
    pthread_exit(NULL);
}
