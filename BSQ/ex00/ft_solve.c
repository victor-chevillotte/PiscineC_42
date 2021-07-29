#include "ft_header.h"

int	ft_check_possible_sqare(t_map map, t_point cur, int lenmax)
{
	int	i;

	i = map.nbobst;
	if (cur.y + lenmax > map.nblines || cur.x + lenmax > map.nbcolumns)
		return (0);
	if (map.nbobst == 0)
		return (1);
	if (cur.y + lenmax > map.nblines - 1 || cur.x + lenmax > map.nbcolumns - 1)
		return (0);
	while (!(map.obstacles[i / 2].y < cur.y - 1)
		&& !(map.obstacles[i / 2].x < cur.x - 1) && i > 0)
		i /= 2;
	while (i < map.nbobst)
	{
		if (map.obstacles[i].y >= cur.y + lenmax
			&& map.obstacles[i].x > cur.x + lenmax)
			return (1);
		if (map.obstacles[i].y >= cur.y
			&& map.obstacles[i].y <= cur.y + lenmax
			&& map.obstacles[i].x >= cur.x
			&& map.obstacles[i].x <= cur.x + lenmax)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_obstacle(t_map obstacles, t_point *current)
{
	int	i;

	i = 0;
	while (i < obstacles.nbobst)
	{
		if (obstacles.obstacles[i].x > (*current).x
			&& obstacles.obstacles[i].y >= (*current).y)
			return (1);
		if (obstacles.obstacles[i].x == (*current).x
			&& obstacles.obstacles[i].y == (*current).y)
			return (0);
		i++;
	}
	return (1);
}

void	ft_show(t_map obstacles, t_point maxpoint, int lenmax)
{
	t_point	current;

	ft_set_point_value(&current, 0, 0);
	while (current.y < obstacles.nblines)
	{
		while (current.x < obstacles.nbcolumns)
		{
			if (!ft_is_obstacle(obstacles, &current))
				ft_putchar(obstacles.obstchar, 1);
			else if (current.x >= maxpoint.x && current.y >= maxpoint.y
				&& current.x < maxpoint.x + lenmax
				&& current.y < maxpoint.y + lenmax)
				ft_putchar(obstacles.fullchar, 1);
			else
				ft_putchar(obstacles.emptychar, 1);
			ft_set_point_value(&current, current.x + 1, current.y);
		}
		ft_putchar('\n', 1);
		ft_set_point_value(&current, 0, current.y + 1);
	}
}

int	ft_sqare_test(t_map obstacles, t_point current, int lenmax)
{
	if (!ft_is_obstacle(obstacles, &current))
		return (0);
	if (ft_check_possible_sqare(obstacles, current, lenmax + 1))
		return (ft_sqare_test(obstacles, current, lenmax + 1));
	if (lenmax != 1)
		return (lenmax + 1);
	return (1);
}

int	ft_solve(t_map obstacles)
{
	t_point	current;
	int		lenmax;
	int		len;
	t_point	maxpoint;

	lenmax = 0;
	ft_set_point_value(&current, 0, 0);
	while (current.y < obstacles.nblines - lenmax)
	{
		while (current.x < obstacles.nbcolumns - lenmax)
		{
			len = ft_sqare_test(obstacles, current, 0);
			if (len > lenmax)
			{
				ft_set_point_value(&maxpoint, current.x, current.y);
				lenmax = len;
			}
			ft_set_point_value(&current, current.x + 1, current.y);
		}
		ft_set_point_value(&current, 0, current.y + 1);
	}
	ft_show(obstacles, maxpoint, lenmax);
	return (1);
}
