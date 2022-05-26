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

	if (argc >= 1)
	{

		if (argv[1] == NULL)
		{
			path = ".";
			dir = opendir(".");
		}
		else
		{

			path = argv[1];
			dir = opendir(path);
		}
		if (chk_no_dir(dir, path) == 1)
		{
			return (0);
		}
		print_dir(dir);
		closedir(dir);
	}
	printf("\n");
	return (0);
}

/**
* chk_no_dir - checks if a directory exists
* @dir: directory object to be checking with
* @path: path to directory to check
*
* Return: void
*/
int chk_no_dir(DIR *dir, char *path)
{
	char *no_access_error;

	if (!dir)
	{
		if (errno == ENOENT)
		{
			no_access_error = str_concat("cannot access ", path);
			perror(no_access_error);
			free(no_access_error);
			return (1);
		}
	}
	return (0);
}

/**
 * print_dir - prints the contents of the directory
 * @dir: the directory object to print
 *
 * Return: void
 */
void print_dir(DIR *dir)
{
	struct dirent *read;

	while (((read = readdir(dir)) != NULL))
	{
		if ((_strncmp(read->d_name, ".", 1) != 0)
			&& _strncmp(read->d_name, "..", 2) != 0)
		{
			printf("%s  ", read->d_name);
		}
	}
}
