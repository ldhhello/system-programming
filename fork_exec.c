// fork_exec.c

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

    if(pid > 0) // 복제된 에 == 복제 당한 애의 pid 받음 
    {
        printf("I'm a parent process.\n");
        x = 1;
        print_pid(x);
    }
    else if(pid == 0) //복제당한애==return 값 0
    {
        printf("I'm a child process.\n");
        x = 2;
        print_pid(x);

        char* args[] = {
            "./exec_test2",
            "hello",
            "world",
            NULL
        };
        if(execv("./exec_test2", args) == -1) //영혼 빙의
        {
            perror("execv() error");
            return -1;
        }
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