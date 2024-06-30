// exec_test.c

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char** argv)
{
    printf("%s pid: %d\n", argv[0], getpid());

    //execl("./exec_test2", "./exec_test2", "hello", "world", NULL);

    sleep(15);

    for(int i=0; i<argc; i++)
        printf("argv%d => %s\n", i, argv[i]);

    return 0;
}