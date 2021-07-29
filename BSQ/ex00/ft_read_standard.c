#include "ft_header.h"

t_map	ft_get_obstpoints_standard(t_map map, char *filemap, int i, int j)
{
	int		nbobst;
	int		start;
	t_point	obst;
	t_point	*obsttab;

	obsttab = malloc(sizeof(obst) * map.nbobst);
	if (!obsttab)
		return (ft_map_error_standard(map, 0, filemap));
	nbobst = 0;
	while (filemap[i] != '\n' && nbobst != map.nbobst)
		i++;
	start = ++i;
	while (filemap[i] != '\0' && nbobst != map.nbobst)
	{
		if (filemap[i] == map.obstchar)
		{
			obst.x = (i - j - start) % map.nbcolumns;
			obst.y = (i - j - start) / map.nbcolumns;
			obsttab[nbobst++] = obst;
		}
		if (filemap[i++] == '\n')
			j++;
	}
	map.obstacles = obsttab;
	return (map);
}

t_map	ft_get_nbobst_standard(t_map map, char *filemap, int i, int nbcolumns)
{
	int	nblines;

	nblines = 1;
	if (map.nbcolumns == 0)
		return (ft_map_error_standard(map, 0, filemap));
	while (filemap[++i] != '\0')
	{
		if (ft_is_mapchar(filemap[i], map) == 1)
			return (ft_map_error_standard(map, 0, filemap));
		if (filemap[i] == map.obstchar)
			map.nbobst++;
		if (filemap[i] == '\n')
		{
			if (nbcolumns != map.nbcolumns)
				return (ft_map_error_standard(map, 0, filemap));
			nbcolumns = -1;
			nblines++;
		}
		nbcolumns ++;
	}
	if (nblines != map.nblines)
		return (ft_map_error_standard(map, 0, filemap));
	return (ft_get_obstpoints_standard(map, filemap, 0, 0));
}

t_map	ft_get_char_standard(t_map map, char *filemap, int sizeOfFirstLine)
{
	int	i;

	i = sizeOfFirstLine + 1;
	map.nbcolumns = 0;
	map.nbobst = 0;
	map.emptychar = filemap[sizeOfFirstLine - 3];
	map.obstchar = filemap[sizeOfFirstLine - 2];
	map.fullchar = filemap[sizeOfFirstLine - 1];
	if (ft_map_args_printable(map) == 1)
		return (ft_map_error_standard(map, 0, filemap));
	if (map.emptychar == map.fullchar || map.fullchar == map.obstchar
		|| map.obstchar == map.emptychar)
		return (ft_map_error_standard(map, 0, filemap));
	while (filemap[i] != '\n')
	{	
		if (ft_is_mapchar(filemap[i], map) == 1)
			return (ft_map_error_standard(map, 0, filemap));
		if (filemap[i] == map.obstchar)
			map.nbobst++;
		map.nbcolumns++;
		i++;
	}
	return (ft_get_nbobst_standard(map, filemap, i, 0));
}

t_map	ft_get_lines_standard(t_map map, int size, int i, int sizeFirstLine)
{
	char	*filetab;

	filetab = ft_reader();
	if (filetab[0] == '\0')
		return (ft_map_error(map, 0));
	while (filetab[size] != '\0')
	{
		if (ft_is_printable(filetab[size]) == 1)
			return (ft_map_error(map, 0));
		size++;
	}
	while (filetab[i] != '\n' && filetab[i] != '\0')
		i++;
	sizeFirstLine = i;
	if (sizeFirstLine < 4)
		return (ft_map_error(map, 0));
	while (i > 3)
	{
		if (ft_is_number(filetab[sizeFirstLine - i]) != 0)
			return (ft_map_error(map, 0));
		map.nblines = 10 * map.nblines + filetab[sizeFirstLine - i--] - '0';
		size--;
	}
	return (ft_get_char_standard(map, filetab, sizeFirstLine));
}

t_map	ft_read_standard(void)
{
	t_map	map;

	map.nblines = 0;
	map.nbcolumns = 0;
	map = ft_get_lines_standard(map, 0, 0, 0);
	if (map.nblines == -1)
		return (map);
	return (map);
}
