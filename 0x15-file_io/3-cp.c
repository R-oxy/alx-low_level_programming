#include "main.h"

/**
 * main - Entry point
 * @argc: The argument count
 * @argv: The argument vector
 *
 * Return: 0 on success, 97 if argc is incorrect
 */
int main(int argc, char **argv)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	copy_file_content(argv[1], argv[2]);
	exit(0);
}

/**
 * copy_file_content - copies content of file_from to file_to
 * @src: The source file
 * @dest: The destination file
 *
 * Return: 0 on success, -1 on error
 */
void copy_file_content(const char *src, const char *dest)
{
	int fd1, fd2, r;
	char buff[1024];

	fd1 = open(src, O_RDONLY);
	if (!src || fd1 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", src);
		exit(98);
	}

	fd2 = open(dest, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	while ((r = read(fd1, buff, 1024)) > 0)
	{
		if (write(fd2, buff, r) != r || fd2 == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", dest);
			exit(99);
		}
	}

	if (r == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", src);
		exit(98);
	}

	if (close(fd1) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd1);
		exit(100);
	}

	if (close(fd2) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd2);
		exit(100);
	}
}
