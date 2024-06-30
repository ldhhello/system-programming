// thread_safe.c

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

int shared = 0;
pthread_mutex_t mutex;

#define MAX_TRY 10000000

void* child_thread_main(void* arg)
{
    int i;

    printf("child thread id %ld started.\n", pthread_self());

    pthread_mutex_lock(&mutex);
    // Critical section (임계영역)
    for(i=0; i<MAX_TRY; i++)
    {
        //pthread_mutex_lock(&mutex);
        shared++;
        //pthread_mutex_unlock(&mutex);
    }

    for(i=0; i<MAX_TRY; i++)
    {
        //pthread_mutex_lock(&mutex);
        shared--;
        //pthread_mutex_unlock(&mutex);
    }

    pthread_mutex_unlock(&mutex);

    printf("child thread id %ld ended.\n", pthread_self());
    return NULL;
}

int main(int argc, char** argv)
{
    if(pthread_mutex_init(&mutex, NULL) != 0)
    {
        perror("pthread_mutex_init() error");
        return -1;
    }

    pthread_t child_thread[2];
    int ret;

    printf("main thread id %ld\n", pthread_self());

    ret = pthread_create(&child_thread[0], NULL, child_thread_main, NULL);
    if(ret)
    {
        perror("pthread_create() error");
    }

    ret = pthread_create(&child_thread[1], NULL, child_thread_main, NULL);
    if(ret)
    {
        perror("pthread_create() error");
    }

    //sleep(12);
    //for(int i=0; i<2; i++)
    //    pthread_join(child_thread[i], NULL);

    printf("trying to join %ld\n", child_thread[0]);
    pthread_join(child_thread[0], NULL);
    printf("trying to join %ld\n", child_thread[1]);
    pthread_join(child_thread[1], NULL);

    printf("main thread ended!!\n");
    printf("shared = %d\n", shared);
    return 0;
}