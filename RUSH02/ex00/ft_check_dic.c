#include "ft_rush.h"

int	ft_check_repeat(t_dicWord *tab, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		if (ft_strcmp(tab[i].nbr, tab[nb].nbr) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_unit(char *tab)
{
	if (ft_strcmp(tab, "100") == 0)
		return (1);
	if (tab[0] == '1')
		if (tab[1] >= '0' && tab[1] <= '9' && tab[2] == 0)
			return (1);
	if (tab[1] == 0)
		if (tab[0] >= '0' && tab[0] <= '9')
			return (1);
	if (tab[0] >= '2' && tab[0] <= '9')
		if (tab[1] == '0')
			return (1);
	return (0);
}

int	ft_check_thousand(char *tab)
{
	int	j;

	j = 1;
	if (tab[0] == '1')
	{
		while (tab[j])
		{
			if (tab[j] != '0')
				return (0);
			j++;
		}
		if (j / 3 <= 12 && j % 3 == 1)
			return (1);
		return (0);
	}
	else
		return (0);
}

int	ft_check_dic(t_dicWord *tab)
{
	int	i;

	i = 0;
	while (tab[i].name)
	{
		if (ft_check_repeat(tab, i))
		{
			ft_putstr("Dict Error\n");
			return (1);
		}
		if (ft_check_unit(tab[i].nbr) || ft_check_thousand(tab[i].nbr))
			tab[i].bol = 0;
		else
			tab[i].bol = 1;
		i++;
	}
	return (0);
}
