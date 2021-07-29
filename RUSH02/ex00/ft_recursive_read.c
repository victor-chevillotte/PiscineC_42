#include "ft_rush.h"

int	ft_hundred(int atoiNB, t_dicWord *tab, char *nb, int i)
{
	char		*u;
	t_dicWord	a;
	t_dicWord	divMax;

	divMax = ft_div_max(nb, tab);
	u = ft_putnbr(atoiNB / 100);
	a = ft_div_max(u, tab);
	if (i)
		write (1, " ", 1);
	ft_putstr(a.name);
	write (1, " ", 1);
	ft_putstr(divMax.name);
	atoiNB -= ft_atoi(u) * 100;
	return (atoiNB);
}

int	ft_twenty(int atoiNB, t_dicWord *tab, int	i)
{
	t_dicWord	a;

	a = ft_div_max(ft_putnbr(atoiNB), tab);
	if (i)
		write(1, " ", 1);
	ft_putstr(a.name);
	atoiNB -= ft_atoi(a.nbr);
	return (atoiNB);
}

int	ft_recursiveOfTriple(char *nb, t_dicWord *tab, int	maxIndex)
{
	int			atoiNB;
	t_dicWord	a;

	atoiNB = ft_atoi(nb);
	if (atoiNB >= 100)
	{
		atoiNB = ft_hundred(atoiNB, tab, nb, maxIndex);
		maxIndex = 1;
	}
	if (atoiNB >= 20)
	{
		atoiNB = ft_twenty(atoiNB, tab, maxIndex);
		maxIndex = 1;
	}
	if (atoiNB > 0)
	{
		a = ft_div_max(ft_putnbr(atoiNB), tab);
		if (maxIndex)
			write(1, " ", 1);
		else
			maxIndex = 1;
		ft_putstr(a.name);
	}

	return (0);
}

int	ft_recursive_triples(char *str, int indexOfTriple,
		int maxIndexTriple, t_dicWord *tab)
{
	int		i;
	char	*strOfTriple;
	int		intOfTriple;

	i = 1;
	intOfTriple = 0;
	if (indexOfTriple < maxIndexTriple)
	{
		strOfTriple = ft_str_of_triple(str, indexOfTriple);
		intOfTriple = ft_atoi(strOfTriple);
		if (indexOfTriple == 0)
			i = 0;
		if (ft_recursiveOfTriple(strOfTriple, tab, i) == 1)
			return (1);

		if (intOfTriple != 0)
			if (ft_print_unit(indexOfTriple + 1, tab, maxIndexTriple, 0) == 1)
				return (1);
		if (indexOfTriple++ < maxIndexTriple)
			ft_recursive_triples(str, indexOfTriple, maxIndexTriple, tab);
	}
	return (0);
}
