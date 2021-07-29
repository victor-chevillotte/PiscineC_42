#include "ft_rush.h"
int	ft_intlen(int input)
{
	int	count;

	count = 0;
	while (input > 0)
	{
		count++;
		input /= 10;
	}
	return (count);
}

char	*ft_rev_char_tab(char *tab, int size)
{
	char	*rev_tab;
	int		i;

	rev_tab = malloc(size * sizeof(*rev_tab));
	if (!rev_tab)
		return (0);
	i = 0;
	while (i < size)
	{
		rev_tab[i] = tab[size - i - 1];
		i++;
	}
	i = 0;
	while (i < size)
	{
		tab[i] = rev_tab[i];
		i++;
	}
	rev_tab[i] = '\0';
	return (rev_tab);
}

char	*ft_putnbr(int nbr)
{
	char	*ret;
	int		i;
	char	*base;

	base = "0123456789";
	ret = malloc(ft_intlen(nbr) * sizeof(*ret));
	if (!ret)
		return (0);
	i = 0;
	while (nbr > 0)
	{
		ret[i] = base[nbr % 10];
		nbr /= 10;
		i++;
	}
	ret[i] = '\0';
	return (ft_rev_char_tab(ret, ft_strlen(ret)));
}
