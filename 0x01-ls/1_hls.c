#include "hls.h"
/**
 * main - runs as if LS
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	DIR *dir;
	struct dirent *read;

	if (argc >= 1)
	{
		if (argv[1] == NULL)
		{
			dir = opendir(".");
			while (((read = readdir(dir)) != NULL) && (_strcmp(read->d_name,
					".") != 0) && (_strcmp(read->d_name, "..") != 0))
					printf("%s  ", read->d_name);
		}
		else
		{
			dir = opendir(argv[1]);
			while ((read = readdir(dir)) != NULL)
				printf("%s\n", read->d_name);
		}
		closedir(dir);
	}

	printf("\n");
	return (0);
}
