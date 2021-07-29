#include "ft_header.h"
t_map	ft_map_error(t_map map, int ismalloced)
{
	ft_putstr("map error\n", 2);
	map.nblines = -1 - ismalloced;
	return (map);
}

int	ft_is_mapchar(char c, t_map map)
{
	if (c != map.obstchar && c != map.emptychar && c != '\n')
		return (1);
	return (0);
}

t_map	ft_map_error_standard(t_map map, int ismalloced, char *filemap)
{
	ft_putstr("map error\n", 2);
	free(filemap);
	map.nblines = -1 - ismalloced;
	return (map);
}

char	*ft_reader(void)
{
	int		count;
	char	mini_buff;
	char	buff[20000];
	char	*str;

	count = 0;
	while (read(0, &mini_buff, 1))
		buff[count++] = mini_buff;
	buff[count] = 0;
	str = malloc(count * sizeof(char));
	count = -1;
	while (buff[++count])
		str[count] = buff[count];
	str[count] = 0;
	return (str);
}
