// signal.c

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void signal_handler(int signum)
{
    printf("%d signal received.\n", signum);
}

int main(int argc, char** argv)
{
    signal(SIGTERM, signal_handler); //15번 시그널
    signal(SIGINT, SIG_IGN); // 2번 시그널 무시
    signal(SIGKILL, SIG_IGN); // 9번 시그널 무시

    while(1)
    {
        printf("loop...\n");
        sleep(1);
    }

    return 0;
}