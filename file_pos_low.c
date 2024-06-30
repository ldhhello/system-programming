// file_pos_low.c
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int write_to_file()
{
    int fd;
    fd = open("donghyun.txt", O_WRONLY | O_CREAT, 0644);

    if(fd == -1)
    {
        printf("open failed\n");
        return -1;
    }

    printf("offset1 = %ld\n", lseek(fd, 0, SEEK_CUR));
    //write(fd, "Hello\n", 6);
    dprintf(fd, "Hello\n");
    printf("offset2 = %ld\n", lseek(fd, 0, SEEK_CUR));
    //write(fd, "World\n", 6);
    dprintf(fd, "World\n");
    printf("offset3 = %ld\n", lseek(fd, 0, SEEK_CUR));

    close(fd);
    return 0;
}

int read_from_file()
{
    int fd;
    char buf[1024];

    fd = open("donghyun.txt", O_RDONLY);

    if(fd == -1)
    {
        printf("open failed\n");
        return -1;
    }

    printf("offset1 = %ld\n", lseek(fd, 0, SEEK_CUR));
    memset(buf, 0, sizeof buf);

    read(fd, buf, sizeof buf);
    
    printf("%s", buf);
    printf("offset2 = %ld\n", lseek(fd, 0, SEEK_CUR));

    lseek(fd, 0, SEEK_END);

    printf("offset3 = %ld\n", lseek(fd, 0, SEEK_CUR));

    return 0;
}

int main(int argc, char** argv)
{
    if(write_to_file())
    {
        printf("write_to_file failed\n");
        return -1;
    }
    if(read_from_file())
    {
        printf("read_from_file failed\n");
        return -1;
    }
}