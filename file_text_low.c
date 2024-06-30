#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int read_from_file()
{
    int fd = open("donghyun.txt", O_RDONLY);
    char buf[1024];

    if(fd == -1)
    {
        printf("File open failed");
        return -1;
    }

    memset(buf, 0, sizeof buf);

    int result = read(fd, buf, 1024);

    if(result == -1)
    {
        printf("read failed\n");
        return -1;
    }

    printf("%s", buf);
    close(fd);

    return 0;
}

int write_to_file()
{
    int fd = open("donghyun.txt", O_WRONLY | O_CREAT, 0644);

    if(fd == -1)
    {
        printf("File open failed\n");
        return -1;
    }

    char* str = "hello, world\n";

    if(write(fd, str, strlen(str)) == -1)
    {
        printf("write failed\n");
        close(fd);
        return -1;
    }

    close(fd);

    return 0;
}

int append_to_file()
{
    int fd = open("donghyun.txt", O_WRONLY | O_APPEND, 0644);

    if(fd == -1)
    {
        printf("File open failed\n");
        return -1;
    }

    char* str = "hello, again\n";

    if(write(fd, str, strlen(str)) == -1)
    {
        printf("write failed\n");
        close(fd);
        return -1;
    }

    close(fd);

    return 0;
}

int main(int argc, char** argv)
{
    if(write_to_file())
    {
        printf("error on write_to_file\n");
        return -1;
    }

    if(read_from_file())
    {
        printf("error on read_from_file\n");
        return -1;
    }

    if(append_to_file())
    {
        printf("error on append_to_file\n");
        return -1;
    }

    return 0;
}