#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <pwd.h>
#include <grp.h>

int main (int argc, char *argv[])
{
    DIR *dir;
    struct dirent *read;
    struct stat sb;
    struct passwd *usr;
    struct group *grp;
    char *str_time;
    //printf("%s %s ", getpwuid(sb.st_uid), getgrgid(sb.st_gid));
    //char *time = ctime(&(buf.st_mtime));

    if (argc >= 1)
    {
        dir = opendir(argv[1]);
        if (lstat(argv[1], &sb) == -1)
            return(-1);
        else
        {
            usr = getpwuid(sb.st_uid);
            grp = getgrgid(sb.st_gid);
            str_time = ctime(&(sb.st_mtime));
            while ((read = readdir(dir)) != NULL)
                {
                    //-rw-rw-r-- 0 Apr 18 14:04 file
                    printf((S_ISDIR(sb.st_mode)) ? "d" : "-");
                    printf((sb.st_mode & S_IRUSR) ? "r" : "-");
                    printf((sb.st_mode & S_IWUSR) ? "w" : "-");
                    printf((sb.st_mode & S_IXUSR) ? "x" : "-");
                    printf((sb.st_mode & S_IRGRP) ? "r" : "-");
                    printf((sb.st_mode & S_IWGRP) ? "w" : "-");
                    printf((sb.st_mode & S_IXGRP) ? "x" : "-");
                    printf((sb.st_mode & S_IROTH) ? "r" : "-");
                    printf((sb.st_mode & S_IWOTH) ? "w" : "-");
                    printf((sb.st_mode & S_IXOTH) ? "x" : "-");
                    printf(" %s %s ", usr->pw_name, grp->gr_name);
                    printf("%lu", sb.st_size);
                    printf(" %s ", str_time);
                    printf("%s\n", read->d_name);
                }
            closedir(dir);
        }
    }
    return (0);
}
