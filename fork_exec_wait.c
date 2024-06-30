// fork_exec_wait.c

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void print_pid(int x)
{
    printf("parent pid : %d, current pid : %d, x : %d\n", getppid(), getpid(), x);
}

int main(int argc, char** argv) 
{
    int x = 0;
    pid_t pid;
    int exit_status;

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

        char* args[] = {
            "./exec_test2",
            "hello",
            "world",
            NULL
        };
        if(execv("./exec_test2", args) == -1)
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

    // 자식프로세스 종료 대기
    pid = wait(&exit_status); // 자식 프로세스가 죽으면서 반환한 반환 값
    if (WIFEXITED(exit_status))
    {
        printf("child pid:  %d, exit status: %d\n", pid, WEXITSTATUS(exit_status));
    }
    
    if(WIFSIGNALED(exit_status))
    {
        printf("child pid: %d, signal: %d\n", pid, WTERMSIG(exit_status));
    }

    return 0;
}