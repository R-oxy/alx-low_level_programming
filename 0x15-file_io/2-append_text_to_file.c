#include "main.h"

/**
  * append_text_to_file - the function name
  * @filename: parameter of type const char *.
  * @text_content: parameter of type char *.
  * Return: int .
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, bytes_written, len = 0;

	if (filename == NULL)
	{
		return (-1);
	}
	if (text_content)
	{
		while (text_content[len])
		len++;
	}
	fd = open(filename, O_WRONLY | O_APPEND);
	if (text_content)
	{
		bytes_written = write(fd, text_content, len);
		if (bytes_written == -1)
		{
			close(fd);
			return (-1);
		}
	}
	close(fd);
	return (1);
}
