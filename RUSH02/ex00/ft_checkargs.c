#include "ft_rush.h"

int	ft_print_error(void)
{
	ft_putstr("Error\n");
	return (-1);
}

int	ft_checkargs2(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 3)
	{
		while (argv[2][i])
		{
			if (argv[2][i] < '0' || argv[2][i] > '9')
				return (ft_print_error());
			i++;
		}
	}
	if (i > 39)
		return (ft_print_error());
	return (0);
}

int	ft_checkargs(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 1 || argc > 3)
		return (ft_print_error());
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] < '0' || argv[1][i++] > '9')
				return (ft_print_error());
		}
		if (i > 39)
			return (ft_print_error());
	}
	return (ft_checkargs2(argc, argv));
}
