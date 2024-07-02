#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        printf("Usage: %s src dest\n", argv[0]);
        return -1;
    }

    char* src = argv[1], *dest = argv[2];

    int src_fd = open(src, O_RDONLY);
    int dst_fd = open(dest, O_WRONLY | O_CREAT, 0644);

    if(src_fd < 0 || dst_fd < 0)
    {
        printf("open failed\n");
        return -1;
    }

    int sz;
    char buf[1024];
    while((sz = read(src_fd, buf, 1024)) > 0)
    {
        write(dst_fd, buf, sz);
    }

    close(src_fd);
    close(dst_fd);

    printf("%s -> %s copied.\n", argv[1], argv[2]);
}