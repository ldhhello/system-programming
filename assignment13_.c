#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char** argv) {
    
    if(argc < 2) {
        printf("Usage: %s src dest\n", argv[0]);
        return -1;
    }

    char *src = argv[1], *dest = argv[2];

    int fd1 = open(src, O_RDONLY);

    if(fd1 < 0) {
        printf("Open failed\n");
        return -1;
    }

    int fd2 = open(dest, O_WRONLY | O_CREAT, 0644);

    if(fd2 < 0) {
        printf("Open failed\n");
        return -1;
    }

    int size;
    char buffer[1024];

    while((size = read(fd1, buffer, 1024)) > 0) {
        write(fd2, buffer, size);
    }

    close(fd1);
    close(fd2);

    printf("%s -> %s copied.\n", argv[1], argv[2]);
}