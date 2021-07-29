#include "ft_header.h"

int	main(int ac, char **av)
{
	t_map	map;
	int		i;

	i = 1;
	if (ac == 1)
	{
		map = ft_read_standard();
		if (map.nblines < 0)
			return (1);
		ft_solve(map);
		free(map.obstacles);
		return (0);
	}
	while (i < ac)
	{
		map = ft_readFile(av[i]);
		if (map.nblines > 0)
			ft_solve(map);
		if (ac != 2)
			ft_putstr("\n", 2);
		i++;
	}
	return (0);
}
