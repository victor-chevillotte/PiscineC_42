#include "ft_rush.h"

int	ft_error_file(int fd)
{
	if (fd == -1)
	{	
		ft_putstr("Dict Error\n");
		return (-1);
	}
	return (0);
}

int	ft_file_read2(char *path)
{
	int		fd;
	int		size;
	char	dico;

	size = 0;
	fd = open(path, O_RDWR);
	if (ft_error_file(fd) == -1)
		return (-20);
	while (read(fd, &dico, 1))
	{
		if (ft_error_file(fd) == -1)
			return (-20);
		size++;
	}
	close(fd);
	if (ft_error_file(fd) == -1)
		return (-20);
	return (size);
}

char	*ft_file_read(char *path)
{
	int		fd;
	char	dico;
	char	*res;
	int		size;

	size = ft_file_read2(path);
	fd = open(path, O_RDWR);
	res = malloc((size + 1) * sizeof(char));
	if (!res)
		return (NULL);
	fd = open (path, O_RDWR);
	if (ft_error_file(fd) == -1)
		return (NULL);
	size = 0;
	while (read(fd, &dico, 1))
	{
		if (ft_error_file(fd) == -1)
			return (NULL);
		res[size++] = dico;
	}
	close (fd);
	if (ft_error_file(fd) == -1)
		return (NULL);
	res[size] = 0;
	return (res);
}
