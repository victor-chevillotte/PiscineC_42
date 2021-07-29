#include "ft_header.h"

void	ft_set_point_value(t_point *pt, int x, int y)
{
	pt->x = x;
	pt->y = y;
}

void	ft_swap(t_point *pt1, t_point *pt2)
{
	t_point	tmp;

	tmp = *pt1;
	*pt1 = *pt2;
	*pt2 = tmp;
}
