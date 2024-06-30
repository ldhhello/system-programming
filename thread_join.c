// thread_join.c

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

void* child_thread_main(void* arg)
{
    int i;

    printf("child thread id %ld started.\n", pthread_self());

    for(i = 100; i >= 0; i -= 10)
    {
        printf("[%s] %d\n", (char*)arg, i);
        sleep(1);
    }

    printf("child thread id %ld ended.\n", pthread_self());
    return NULL;
}

int main(int argc, char** argv)
{
    pthread_t child_thread[2];
    int ret;

    printf("main thread id %ld\n", pthread_self());

    ret = pthread_create(&child_thread[0], NULL, child_thread_main, "runner1"); //왼 손 생성
    if(ret)
    {
        perror("pthread_create() error");
    }

    ret = pthread_create(&child_thread[1], NULL, child_thread_main, "runner2"); // 오른 손 생성
    if(ret)
    {
        perror("pthread_create() error");
    }

    //sleep(12);
    //for(int i=0; i<2; i++)
    //    pthread_join(child_thread[i], NULL);

    printf("trying to join %ld\n", child_thread[0]);
    pthread_join(child_thread[0], NULL); //끝날때까지 대기
    printf("trying to join %ld\n", child_thread[1]);
    pthread_join(child_thread[1], NULL);

    printf("main thread ended!!");
    return 0;
}