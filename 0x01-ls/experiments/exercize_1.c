#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    DIR *dir;
    struct dirent *read;

    if (argc >= 1)
    {
        dir = opendir(argv[1]);
        while ((read = readdir(dir)) != NULL)
            printf("%s\n", read->d_name);
        closedir(dir);
    }
    return (0);
}
