#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>

#define MAXLINE 128

static void sig_int(int);

int main()
{
    char buf[MAXLINE];
    pid_t pid;
    int status;

    if(signal(SIGINT, sig_int) == SIG_ERR) {
        printf("signal error!");
    }

    printf(">");
    while(fgets(buf, MAXLINE, stdin) != NULL) {
        if(buf[strlen(buf) - 1] == '\n') {
            buf[strlen(buf) - 1] = '\0';
        }

        if((pid = fork()) < 0) {
            printf("fork error!\n");
        } else if(pid == 0) {
            execlp(buf, buf, (char *)0);
            printf("execute error\n");
            return -1;
        }
        if((pid = waitpid(pid, &status, 0)) < 0) {
            printf("waitpid error\n");
        }
        printf(">");
    }
    return 0;
}

void sig_int(int signo)
{
    printf("interrupt\n>");
}
