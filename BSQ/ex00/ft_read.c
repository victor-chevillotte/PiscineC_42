#include "ft_header.h"

t_map	ft_get_obstpoints(t_map map, int file_read, int i)
{
	int		nbobst;
	t_point	obst;
	t_point	*obsttab;	
	char	junk[1];

	obsttab = malloc(sizeof(obst) * map.nbobst);
	if (!obsttab)
		return (ft_map_error(map, 0));
	nbobst = 0;
	while (read(file_read, junk, 1) && nbobst != map.nbobst)
	{
		if (junk[0] == map.obstchar)
		{
			obst.x = (i - 1) % map.nbcolumns;
			obst.y = (i - 1) / map.nbcolumns;
			obsttab[nbobst] = obst;
			nbobst++;
		}
		if (junk[0] == '\n')
			i--;
		i++;
	}
	map.obstacles = obsttab;
	return (map);
}

t_map	ft_get_nbobst(t_map map, int file_read, int nblines, int nbcolumns)
{
	char	junk[1];

	if (map.nbcolumns == 0)
		return (ft_map_error(map, 0));
	while (read(file_read, junk, 1))
	{
		if (ft_is_mapchar(junk[0], map) == 1)
			return (ft_map_error(map, 0));
		if (junk[0] == map.obstchar)
			map.nbobst++;
		if (junk[0] == '\n')
		{
			if (nbcolumns != map.nbcolumns)
				return (ft_map_error(map, 0));
			nbcolumns = -1;
			nblines++;
		}
		nbcolumns ++;
	}
	close(file_read);
	if (nblines != map.nblines)
		return (ft_map_error(map, 0));
	return (map);
}

t_map	ft_get_char(t_map map, int file_read)
{
	char	junk[1];

	map.nbcolumns = 0;
	map.nbobst = 0;
	if (read(file_read, junk, 1))
		map.emptychar = junk[0];
	if (read(file_read, junk, 1))
		map.obstchar = junk[0];
	if (read(file_read, junk, 1))
		map.fullchar = junk[0];
	if (ft_map_args_printable(map) == 1)
		return (ft_map_error(map, 0));
	if (!(read(file_read, junk, 1) && junk[0] == '\n'))
		return (ft_map_error(map, 0));
	while (read(file_read, junk, 1) && junk[0] != '\n')
	{
		if (ft_is_mapchar(junk[0], map) == 1)
			return (ft_map_error(map, 0));
		if (junk[0] == map.obstchar)
			map.nbobst++;
		map.nbcolumns++;
	}
	return (ft_get_nbobst(map, file_read, 1, 0));
}

t_map	ft_get_lines(t_map map, char *filename,
		int size, int file_read)
{
	char	junk[1];

	file_read = open(filename, O_RDONLY);
	if (file_read == -1)
		return (ft_map_error(map, 0));
	while (read(file_read, junk, 1) && junk[0] != '\n')
	{
		if (ft_is_printable(junk[0]) == 1)
			return (ft_map_error(map, 0));
		size++;
	}
	close(file_read);
	if (size < 4)
		return (ft_map_error(map, 0));
	file_read = open(filename, O_RDONLY);
	if (file_read == -1)
		return (ft_map_error(map, 0));
	while (size > 3 && read(file_read, junk, 1))
	{
		if (ft_is_number(junk[0]) != 0)
			return (ft_map_error(map, 0));
		map.nblines = 10 * map.nblines + junk[0] - '0';
		size--;
	}
	return (ft_get_char(map, file_read));
}

t_map	ft_readFile(char *filename)
{
	int		file_read;
	char	junk[1];
	t_map	map;

	map.nblines = 0;
	map.nbcolumns = 0;
	map = ft_get_lines(map, filename, 0, 0);
	if (map.nblines == -1)
		return (map);
	if (map.emptychar == map.fullchar || map.fullchar == map.obstchar
		|| map.obstchar == map.emptychar)
		return (ft_map_error(map, 0));
	file_read = open(filename, O_RDONLY);
	if (file_read == -1)
		return (ft_map_error(map, 0));
	while (read(file_read, junk, 1) && junk[0] != '\n')
		junk[0] = 'l';
	map = ft_get_obstpoints(map, file_read, 1);
	free(map.obstacles);
	close(file_read);
	return (map);
}
