// fork_test.c

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void print_pid(int x)
{
    printf("parent pid : %d, current pid : %d, x : %d\n", getppid(), getpid(), x);
}

int main(int argc, char** argv) 
{
    int x = 0;
    pid_t pid;

    pid = fork();
    printf("fork() 후 pid : %d\n", pid);

    if(pid > 0)
    {
        printf("I'm a parent process.\n");
        x = 1;
        print_pid(x);
    }
    else if(pid == 0)
    {
        printf("I'm a child process.\n");
        x = 2;
        print_pid(x);
    }
    else
    {
        perror("fork() error");
        return -1;
    }

    //printf("pid: %d, x: %d\n", getpid(), x);
    getc(stdin);

    return 0;
}