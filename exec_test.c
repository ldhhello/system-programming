// exec_test.c

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char** argv)
{
    printf("%s pid: %d\n", argv[0], getpid());

    execl("./exec_test2", "./exec_test2", "hello", "world", NULL);

    printf("bye!!\n");

    return 0;
}