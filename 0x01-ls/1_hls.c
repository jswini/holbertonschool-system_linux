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

	printf("1");
	
	if (argc >= 1)
	{
		
	printf("2");

		if (argv[1] == NULL)
		{

	printf("3");
			path = ".";
			dir = opendir(".");
		}
		else
		{

	printf("4");
			path = argv[1];
			dir = opendir(path);
		}
		if (chk_no_dir(dir, path) == 1)
		{

	printf("5");
			return (0);
		}
	printf("6");

		print_dir(dir);
		closedir(dir);
	}
	printf("7");
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

	printf("8");
	//while (((read = readdir(dir)) != NULL) && (_strcmp(read->d_name,
	//		".") != 0) && (_strcmp(read->d_name, "..") != 0))
	
	while (((read = readdir(dir)) != NULL))
	{
		printf("9");
		printf("%s  ", read->d_name);
	}
}
