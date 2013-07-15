#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *dirp;
    char *local = ".";
    char *last = "..";

    if (argc == 1) {
        argv[1] = local;
    }

    if ((dp = opendir(argv[1])) == NULL) {
        printf("can't open %s\n", argv[1]);
    }
    while((dirp = readdir(dp)) != NULL) {
        if(((strcmp(dirp->d_name, local)) == 0) || ((strcmp(dirp->d_name,last)) == 0))
            continue;

        printf("%s\n", dirp->d_name);
    }
    closedir(dp);
    return 0;
}
