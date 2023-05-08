#include "main.h"

/**
  * create_file - the function name
  * @filename: parameter of type const char *.
  * @text_content: parameter of type char *.
  * Return: int .
 */
int create_file(const char *filename, char *text_content)
{
	int fd, count = 0, status;

	if (filename == NULL)
	{
		return (-1);
	}
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (text_content != NULL)
	{
		while (text_content[count] != '\0')
		count++;
		status = write(fd, text_content, count);
		if (status == -1)
		{
			return (-1);
		}
	}
	close(fd);
	return (1);
}
