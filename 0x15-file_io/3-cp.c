#include "main.h"

/**
  * copy_file - the function name
  * @source: parameter of type const char *.
  * @destination: parameter of type const char *.
  * Return: int .
 */
int copy_file(const char *source, const char *destination)
{
	int source_fd, dest_fd;
	ssize_t num_read, num_written;
	char buffer[1024];

	source_fd = open(source, O_RDONLY);
	if (source_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", source);
		return (-1);
	}
	dest_fd = open(destination, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (dest_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", destination);
		close(source_fd);
		return (-1);
	}
	while ((num_read = read(source_fd, buffer, sizeof(buffer))) > 0)
	{
		num_written = write(dest_fd, buffer, num_read);
		if (num_written == -1 || num_written != num_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", destination);
			close(source_fd);
			close(dest_fd);
			return (-1);
		}
	}
	if (num_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", source);
		close(source_fd);
		close(dest_fd);
		return (-1);
	}
	if (close(source_fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", source_fd);
		return (-1);
	}
	if (close(dest_fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", dest_fd);
		return (-1);
	}
	return (0);
}

/**
  * main - The entry point of the program
  * @argc: parameter of type int .
  * @argv: parameter of type char *.
  * Return: int .
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		return (97);
	}
	if (copy_file(argv[1], argv[2]) == -1)
	{
		return (98);
	}
	return (0);
}
