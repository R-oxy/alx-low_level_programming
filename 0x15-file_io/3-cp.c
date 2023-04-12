#include "main.h"

#define BUF_SIZE 1024

/**
 * copy_file - Copy the content of a file to another file
 * @file_from: the path of the source file
 * @file_to: the path of the destination file
 *
 * Return: 0 on success, non-zero on failure
 */
int copy_file(const char *file_from, const char *file_to)
{
        int fd_from, fd_to;
        ssize_t bytes_read, bytes_written;
        char buf[BUF_SIZE];
        mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

        fd_from = open(file_from, O_RDONLY);
        if (fd_from == -1)
	{
                dprintf(STDERR_FILENO,
                        "Error: Can't read from file %s\n", file_from);
                return (98);
        }

        fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, mode);
        if (fd_to == -1)
	{
                dprintf(STDERR_FILENO,
                        "Error: Can't write to file %s\n", file_to);
                return (99);
        }

        while ((bytes_read = read(fd_from, buf, BUF_SIZE)) > 0)
	{
                bytes_written = write(fd_to, buf, bytes_read);
                if (bytes_written == -1 || bytes_written != bytes_read)
		{
                        dprintf(STDERR_FILENO,
                                "Error: Can't write to file %s\n", file_to);
                        return (99);
                }
        }

        if (bytes_read == -1)
	{
                dprintf(STDERR_FILENO,
                        "Error: Can't read from file %s\n", file_from);
                return (98);
        }

        if (close(fd_from) == -1)
	{
                dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
                return (100);
        }

        if (close(fd_to) == -1)
	{
                dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
                return (100);
        }

        return (0);
}

/**
 * main - Entry point, calls copy_file function
 * @argc: the number of arguments passed to the program
 * @argv: an array of strings containing the arguments
 *
 * Return: 0 on success, non-zero on failure
 */
int main(int argc, char *argv[])
{
        if (argc != 3)
	{
                dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
                return (97);
        }

        return (copy_file(argv[1], argv[2]));
}
