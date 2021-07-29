#include "ft_header.h"

int	ft_is_printable(char c)
{
	if ((c < 32 || c == 127) && c != '\n')
		return (1);
	return (0);
}

int	ft_map_args_printable(t_map map)
{
	if (ft_is_printable(map.emptychar) == 0
		&& ft_is_printable(map.fullchar) == 0
		&& ft_is_printable(map.obstchar) == 0)
		return (0);
	return (1);
}

int	ft_is_number(char c)
{
	if (c >= '0' || c <= '9')
		return (0);
	return (1);
}
