#ifndef LS_H
#define LS_H
#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <pwd.h>
#include <grp.h>
#include <errno.h>
int _strcmp(char *s1, char *s2);
char *str_concat(char *s1, char *s2);
int _strlen(char *s);
int chk_no_dir(DIR *dir, char *path);
void print_dir(DIR *dir);
#endif /*LS_H*/
