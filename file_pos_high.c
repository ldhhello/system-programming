// file_pos_high.c
#include <stdio.h>
#include <string.h>

int write_to_file()
{
    FILE* fp;

    fp = fopen("donghyun.txt", "w");

    if(fp == NULL)
    {
        printf("fopen failed\n");
        return -1;
    }

    printf("offset1 = %ld\n", ftell(fp)); // ftell 하면 현재 커서 위치
    fputs("Hello\n", fp); // 파일에다가 Hello\n 출력 (커서위치 바뀜)
    printf("offset2 = %ld\n", ftell(fp));
    fputs("World\n", fp);
    printf("offset3 = %ld\n", ftell(fp));

    fclose(fp);
    return 0;
}

int read_from_file()
{
    FILE* fp;
    char buf[1024];

    fp = fopen("donghyun.txt", "r");

    if(fp == NULL)
    {
        printf("fopen failed\n");
        return -1;
    }

    printf("offset1 = %ld\n", ftell(fp));
    memset(buf, 0, sizeof buf);

    fgets(buf, sizeof(buf), fp);
    printf("%s", buf);
    printf("offset2 = %ld\n", ftell(fp));

    fseek(fp, 0, SEEK_END); // 원하는 곳부터 읽기

    printf("offset3 = %ld\n", ftell(fp));

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