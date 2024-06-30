// signal_send.c

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    pid_t pid;
    union sigval value;

    if(argc < 3)
    {
        printf("Usage: %s PID PAYLOAD\n", argv[0]);
        return -1;
    }

    pid = atoi(argv[1]);
    value.sival_int = atoi(argv[2]);

    sigqueue(pid, SIGUSR1, value); // 10 시그널

    return 0;
}