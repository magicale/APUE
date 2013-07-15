#include <stdio.h>
#include <fcntl.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(void)
{
    int fd;

    if((fd = creat("file.hole", 0777)) < 0) {
        printf("create error\n");
    }

    if(write(fd, buf1, 10) != 10) {
        printf("buf1 write error\n");
    }//offset now 10

    if(lseek(fd, 16384, SEEK_SET) == -1) {
        printf("lseek error\n");
    }//offset now 16384

    if(write(fd, buf2, 10) != 10) {
        printf("buf2 write error\n");
    }

    return 0;
}
