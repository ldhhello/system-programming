// file_link.c
#include <stdio.h>
#include <unistd.h> // 찍었는데 맞네??
#include <errno.h>

#define TARGET_FILE "hello"

int main(int argc, char** argv)
{
    // Hardlink
    if(link(TARGET_FILE, "hello_link"))
    {
        printf("error code: %d\n", errno);
        perror("error msg");
        return -1;
    }

    // Softlink
    if(symlink(TARGET_FILE, "hello_symlink"))
    {
        printf("error code: %d\n", errno);
        perror("error msg");
        return -1;
    }

    return 0;
}