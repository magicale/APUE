#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>

#define MAXLINE 128
int main(void)
{
    char buf[MAXLINE];
    pid_t pid;
    int status;

    printf(">");
    while(fgets(buf, MAXLINE, stdin) != NULL) {
        if(buf[strlen(buf) - 1] == '\n') {
            buf[strlen(buf) - 1] = 0;
        }

        if((pid = fork()) < 0) {
            printf("fork error!\n");
        } else if(pid == 0) {
            execlp(buf, buf, (char *)0);
            printf("can not execute: %s\n", buf);
            return -1;
        }
        if((pid = waitpid(pid, &status, 0)) < 0) {
            printf("waitpid error!\n");
        }
        printf(">");
    }
    return 0;
}
