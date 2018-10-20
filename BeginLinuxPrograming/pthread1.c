#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void *thread_func(void *arg);

char message[] = "Hello World";

int main()
{
    int res;
    pthread_t a_thread;
    void *thread_result;

    res = pthread_create(&a_thread, NULL, thread_func, (void*)message);
    if(res != 0) {
        perror("thread create failed"); 
        exit(EXIT_FAILURE);
    }
    printf("Waiting for thread to finish...\n");

    res = pthread_join(a_thread, &thread_result);
    if(res != 0) {
        perror("thread join failed"); 
        exit(EXIT_FAILURE);
    }
    printf("thread joined, returned %s\n", (char*)thread_result);
    printf("message is now %s\n", message);
    exit(EXIT_SUCCESS);

}


void *thread_func(void *arg)
{
    printf("thread func is running, arg is  %s\n", (char*)arg);
    sleep(3);
    strcpy(message, "Bye!");
    pthread_exit("Thank you for the cup time\n");


}
