#include "hls.h"
/**
 * _strncmp - compares strings and returns 0 if same or a number if different
 * @s1: first string
 * @s2: second string
 * @size: number of chars to compare in string
 *
 * Return: 0 if same, pos if s1 < s2 or neg if s1 < s2
 */
int _strncmp(char *s1, char *s2, size_t size)
{
	int i;

	for (i = 0; size > 0; i++, size--)
	{
		if (s1[i] == s2[i])
			continue;
		else
			return (s1[i] - s2[i]);
	}
	return (0);
}

/**
 * _strlen - determines how long a string is
 * @s: the input string to measure
 *
 * Return: length of the string
 */
int _strlen(char *s)
{
	int count;

	for (count = 0; *(s + count) != '\0'; count++)
	{}
	return (count);
}

/**
 * str_concat - concatenates 2 strings
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer to new string if success, null if failed
 */
char *str_concat(char *s1, char *s2)
{
	int len1, len2, i;
	char *dest;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	len1 = _strlen(s1);
	len2 = _strlen(s2);
	dest = malloc((sizeof(char) * len1) + (sizeof(char) * len2) + 1);
	if (dest == NULL)
		return (NULL);
	for (i = 0; i < len1; i++)
		dest[i] = s1[i];
	for (i = len1; i < (len1 + len2); i++)
		dest[i] = s2[i - len1];
	dest[len1 + len2] = '\0';
	return (dest);
}

/**
 * check_file_type - determines lstat mode of the file
 * @path: location of file to check
 * Return: -1 if error, pos int for other result
 */
int check_file_type(char *path)
{
	struct stat sb;

	if (lstat(path, &sb) == -1)
		return (-1);
	if ((sb.st_mode & S_IFMT) == S_IFREG)
	{
		print_file_name(path);
		return (1);
	}
	else if ((sb.st_mode & S_IFMT) == S_IFDIR)
	{
		return (2);
	}
	else
	{
		printf("not a file or directory");
		return (3);
	}
}

/**
 * print_file_name - prints a file name if regfile
 * @path: location of file
 * return: Void
 */
void print_file_name(char *path)
{
	printf("%s\n", path);
}
