#include "main.h"

static int *open_files(const char *file_from, const char *file_to);
static int copy_data(int fd_from, int fd_to);
static void close_files(int *fds);

#define BUFFER_SIZE 1024

/**
 * main - Entry point of the program
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: On success, return 0. On error, return a non-zero value
 */
int main(int argc, char **argv)
{
	int status;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		return (97);
	}

	status = copy_file(argv[1], argv[2]);
	if (status)
		return (status);

	return (0);
}

/**
 * open_files - Opens the source and destination files for copying.
 * @file_from: The name of the source file.
 * @file_to: The name of the destination file.
 *
 * Return: An array containing the file descriptors of the opened files.
 *         The first element is the source file descriptor, and the second
 *         element is the destination file descriptor.
 */
static int *open_files(const char *file_from, const char *file_to)
{
	int *fds = malloc(sizeof(int) * 2);

	if (fds == NULL)
		return (NULL);

	fds[0] = open(file_from, O_RDONLY);
	if (fds[0] == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		free(fds);
		return (NULL);
	}

	fds[1] = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fds[1] == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		close(fds[0]);
		free(fds);
		return (NULL);
	}

	return (fds);
}

/**
 * copy_data - Copies data from the source file to the destination file.
 * @fd_from: The file descriptor of the source file.
 * @fd_to: The file descriptor of the destination file.
 *
 * Return: 0 on success, non-zero on failure.
 */
static int copy_data(int fd_from, int fd_to)
{
	int read_status, write_status;
	char buffer[BUFFER_SIZE];

	while ((read_status = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		write_status = write(fd_to, buffer, read_status);
		if (write_status != read_status)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to file descriptor %d\n", fd_to);
			return (EXIT_FAILURE);
		}
	}

	if (read_status == -1)
	{
		dprintf(STDERR_FILENO, "Error: Cant read frm file descriptor %d\n", fd_from);
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}

/**
 * close_files - Closes the file descriptors of the opened files.
 * @fds: An array containing the file descriptors of the opened files.
 *
 * Return: 0 on success, or -1 on failure.
 */
static void close_files(int *fds)
{
	close(fds[0]);
	close(fds[1]);
	free(fds);
}

/**
 * copy_file - Copies the content of one file to another.
 * @file_from: The name of the source file.
 * @file_to: The name of the destination file.
 *
 * Return: 0 on success, non-zero on failure.
 */
int copy_file(const char *file_from, const char *file_to)
{
	int *fds;
	int status;

	fds = open_files(file_from, file_to);
	if (fds == NULL)
		return (EXIT_FAILURE);

	status = copy_data(fds[0], fds[1]);

	close_files(fds);

	return (status);
}
