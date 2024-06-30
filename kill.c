// kill.c

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    pid_t pid;
    int signum;

    if(argc < 3)
    {
        printf("Usage: %s PID SIGNUM\n", argv[0]);
        return -1;
    }

    pid = atoi(argv[1]);
    signum = atoi(argv[2]);

    kill(pid, signum);

    printf("%d signal sent.\n", signum);

    return 0;
}