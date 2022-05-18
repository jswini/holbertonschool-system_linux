#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
    DIR *dir;
    struct dirent *read;
    struct stat sb;

    if (argc >= 1)
    {
        dir = opendir(argv[1]);
        if (lstat(argv[1], &sb) == -1)
            return(-1);
        else
        {
            while ((read = readdir(dir)) != NULL)
                {
                    printf("%s ", read->d_name);
                    printf("%lu\n", sb.st_size);
                }
            closedir(dir);
        }
    }
    return (0);
}
