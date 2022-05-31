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
#include <time.h>
int _strncmp(char *s1, char *s2, size_t size);
char *str_concat(char *s1, char *s2);
int _strlen(char *s);
int chk_no_dir(char *argv, DIR *dir, char *path);
void print_dir(DIR *dir);
void print_mult_dir(char *path, DIR *dir, int i, int argc);
int check_file_type(char *path);
void print_file_name(char *path);
#endif /*LS_H*/
