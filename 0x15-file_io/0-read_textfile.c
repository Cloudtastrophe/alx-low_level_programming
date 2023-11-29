#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * read_textfile - Reads a text file and prints the specified number of letters.
 * @filename: Name of the file.
 * @letters: Number of letters to print.
 *
 * Return: Number of letters printed on success; 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t nrd, nwr;
	char *buf;

	if (!filename)
		return (0);

	/* Open file in read-only mode */
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	/* Allocate memory for the buffer */
	buf = malloc(sizeof(char) * letters);
	if (!buf)
	{
		close(fd);
		return (0);
	}

	/* Read up to 'letters' bytes from the file into the buffer */
	nrd = read(fd, buf, letters);

	/* Write the read content to the standard output */
	nwr = write(STDOUT_FILENO, buf, nrd);

	/* Close file descriptor and free allocated memory */
	close(fd);
	free(buf);

	return (nwr);
}
