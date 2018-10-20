#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void *thread_func(void *arg);

char message[] = "Hello World";
int run_now = 1;

int main()
{
    int res;
    pthread_t a_thread;
    void *thread_result;
    int count1 = 0;

    res = pthread_create(&a_thread, NULL, thread_func, (void*)message);
    if(res != 0) {
        perror("thread create failed"); 
        exit(EXIT_FAILURE);
    }
    
    while(count1 ++ < 20) {
        if(run_now == 1) {
            printf("1");
            run_now = 2;
        }
        else {
            sleep(1);
        }
    }

    printf("\nWaiting for thread to finish...\n");

    res = pthread_join(a_thread, &thread_result);
    if(res != 0) {
        perror("thread join failed"); 
        exit(EXIT_FAILURE);
    }
    printf("thread joined, returned %s\n", (char*)thread_result);
    exit(EXIT_SUCCESS);

}


void *thread_func(void *arg)
{
    int count2 = 0;
    while(count2 ++ < 20) {
        if(run_now == 2) {
            printf("2");
            run_now = 1;
        }
        else {
            sleep(1);
        }
    }
    pthread_exit("Thank you for the cup time\n");

}
