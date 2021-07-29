#include "ft_rush.h"

int	ft_recursive_read(char *str, t_dicWord *tab)
{
	int			grpOf3;
	int			i;
	t_dicWord	a;

	if (str[0] == '\0')
	{
		a = ft_div_max("0", tab);
		ft_putstr(a.name);
		return (0);
	}
	i = 0;
	grpOf3 = ft_strlen_triple(str);
	if (ft_recursive_triples(str, 0, grpOf3, tab) == 1)
		return (1);
	ft_putstr("\n");
	return (0);
}

int	ft_print_unit(int power, t_dicWord *tab, int indexMax, int i)
{
	char		*result;
	t_dicWord	div;

	if (power == indexMax)
		return (0);
	if (power == 0)
		return (0);
	power = indexMax - power;
	result = malloc(sizeof(char) * (3 * power + 2));
	if (result == NULL)
		return (1);
	result[0] = '1';
	while (++i <= (3 * power))
		result[i] = '0';
	result[i] = 0;
	div = ft_div_max(result, tab);
	free(result);
	if (ft_strcmp(div.nbr, "-1") == 0)
		return (1);
	write(1, " ", 1);
	ft_putstr(div.name);
	return (0);
}
