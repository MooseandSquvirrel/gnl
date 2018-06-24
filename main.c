#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int fd;
	char *line;
	int i = 1;

	if (argc < 2)
		return (0);
	while (argv[i])
	{
		printf("just do it\n");
		fd = open(argv[i], O_RDONLY);
		printf("Fd complete = %d\n", fd);
		while (get_next_line(&line, fd))
		{
			printf("Main - %s\n", line);
			free(line);
		}
		close(fd);
		i++;
	}
	return (0);
}
