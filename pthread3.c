#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

void *thread_func(void *arg);

sem_t sem;
#define WORK_SIZE 1024
char work_area[WORK_SIZE];


int main()
{
    int res;
    pthread_t a_thread;
    void *thread_result;

    res = sem_init(&sem, 0, 0);
    if(res != 0) {
        perror("semaphore init failed"); 
        exit(EXIT_FAILURE);
    }

    res = pthread_create(&a_thread, NULL, thread_func, NULL);
    if(res != 0) {
        perror("thread create failed"); 
        exit(EXIT_FAILURE);
    }
    
    printf("input some text, enter end to finish\n");
    while(strncmp("end", work_area, 3) != 0) {
        if(strncmp("FAST", work_area, 4) == 0) {
            sem_post(&sem);
            strcpy(work_area, "shit\0");
        
        }
        else {
            fgets(work_area, WORK_SIZE, stdin);
            sem_post(&sem);
        }
    }

    printf("\nWaiting for thread to finish...\n");
    res = pthread_join(a_thread, &thread_result);
    if(res != 0) {
        perror("thread join failed"); 
        exit(EXIT_FAILURE);
    }
    printf("thread joined, returned\n");
    sem_destroy(&sem);
    exit(EXIT_SUCCESS);

}


void *thread_func(void *arg)
{
    sem_wait(&sem);
    while(strncmp("end", work_area, 3) != 0) {
        printf("you input %d chars\n",strlen(work_area) - 1);
        sem_wait(&sem);
    }
    pthread_exit("NULL");

}
