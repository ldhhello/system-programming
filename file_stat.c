#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char** argv) 
{
    struct stat statbuf;

    if(argc < 2)
    {
        printf("Usage: %s filename\n", argv[0]);
        return -1;
    }

    if(lstat(argv[1], &statbuf)) // 파일 종류
    {
        perror("error msg");
        return 1;
    }

    printf("size: %ld\n", statbuf.st_size);
    if(S_ISDIR(statbuf.st_mode))
    {
        printf("Directory\n");
    }
    else if(S_ISREG(statbuf.st_mode))
    {
        printf("Regular file\n");
    }
    else if(S_ISLNK(statbuf.st_mode))
    {
        printf("Symbolic link file\n");
    }
    else
    {
        printf("???\n");
    }

    return 0;
}