#include <stdio.h>
#include <string.h>

int read_from_file()
{
    FILE* fp = fopen("donghyun.txt", "r");
    char buf[1024];

    if(fp == NULL)
    {
        printf("File open failed");
        return -1;
    }

    memset(buf, 0, sizeof buf);

    fgets(buf, sizeof buf, fp);

    printf("%s", buf);
    fclose(fp);

    return 0;
}

int write_to_file()
{
    FILE* fp;
    fp = fopen("donghyun.txt", "w");

    if(fp == NULL)
    {
        printf("File open failed");
        return -1;
    }

    fputs("Hello, world!", fp);

    fclose(fp);

    return 0;
}

int main(int argc, char** argv)
{
    if(write_to_file())
    {
        printf("error\n");
        return -1;
    }

    if(read_from_file())
    {
        printf("error on read_from_file\n");
        return -1;
    }

    return 0;
}