#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: The name of the file.
 * @text_content: The content to be appended.
 *
 * Return: 1 on success, -1 if the file does not exist or if it fails.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	int nletters;
	int rwr;

	if (!filename)
		return (-1);

	/* Open file with write and append flags */
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content)
	{
		/* Count the number of letters in text_content */
		for (nletters = 0; text_content[nletters]; nletters++)
			;

		/* Write nletters from text_content to the file */
		rwr = write(fd, text_content, nletters);

		if (rwr == -1)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);

	return (1);
}
