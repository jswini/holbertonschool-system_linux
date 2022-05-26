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
	char *path;
	int i;

	if (argc >= 1)
	{
		for (i = 1; i < argc; i++)
		{
			if (argv[1] == NULL)
			{
				path = ".";
				dir = opendir(".");
			}
			else
			{
				path = argv[i];
				dir = opendir(path);
			}
			if (chk_no_dir(*argv, dir, path) == 1)
			{
				return (0);
			}
			print_dir(dir, path);
			if ((i + 1) != argc)
			{
				printf("\n");
			}
			closedir(dir);
		}
	}
	return (0);
}

/**
* chk_no_dir - checks if a directory exists
* @dir: directory object to be checking with
* @path: path to directory to check
* @argv: array of arguments to main
*
* Return: void
*/
int chk_no_dir(char *argv, DIR *dir, char *path)
{
	char *program_name;
	char *no_access_error;
	char *cannot_access;

	if (!dir)
	{
		program_name = &argv[0];
		if (errno == ENOENT)
		{
			cannot_access = str_concat(program_name, ": cannot access ");
			no_access_error = str_concat(cannot_access, path);
			perror(no_access_error);
			free(cannot_access);
			free(no_access_error);
			return (1);
		}
	}
	return (0);
}

/**
 * print_dir - prints the contents of the directory
 * @dir: the directory object to print
 * @path: name of directory object
 *
 * Return: void
 */
void print_dir(DIR *dir, char *path)
{
	struct dirent *read;

	printf("%s:\n", path);
	while (((read = readdir(dir)) != NULL))
	{
		if ((_strncmp(read->d_name, ".", 1) != 0)
			&& _strncmp(read->d_name, "..", 2) != 0)
		{
			printf("%s  ", read->d_name);
		}
	}
	printf("\n");
}
