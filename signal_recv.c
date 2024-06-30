// signal_recv.c

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>

void sigusr1_handler(int signum, siginfo_t* info, void* ucontext)
{
    printf("sigusr1_handler started\n");

    if(info->si_code & SI_QUEUE)
    {
        printf("signal from sigqueue(), payload %d\n", info->si_int);
    }
    else
    {
        printf("signal from kill\n");
    }
}

int main(int argc, char** argv)
{
    struct sigaction act;

    memset(&act, 0, sizeof(struct sigaction));
    act.sa_sigaction = sigusr1_handler;
    act.sa_flags = SA_SIGINFO;

    if(sigaction(SIGUSR1, &act, NULL) != 0)
    {
        perror("sigaction() error");
        return -1;
    }

    while(1)
    {
        printf("loop...\n");
        sleep(1);
    }

    return 0;
}