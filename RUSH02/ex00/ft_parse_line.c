#include "ft_rush.h"

int	ft_malloc_number(int k, t_dicWord *structTab, char *dico, int i)
{
	char	*tmpTab;
	int		l;
	int		j;

	j = 0;
	while (!(dico[i] >= '0' && dico[i] <= '9'))
		if (dico[i] != ' ' && dico[i++] != '\n')
			return (ft_free_struct(structTab, k));
	while (dico[i + j] >= '0' && dico[i + j] <= '9')
		j++;
	l = 0;
	tmpTab = malloc(sizeof(char) * (j + 1));
	if (!tmpTab)
	{
		return (ft_free_struct(structTab, k));
	}
	tmpTab[j] = '\0';
	while (l < j)
		tmpTab[l++] = dico[i++];
	structTab[k].nbr = tmpTab;
	return (i);
}

int	ft_malloc_name(int k, t_dicWord *structTab, char *dico, int i)
{
	char	*tmpTab;
	int		l;
	int		j;
	int		y;

	j = 0;
	y = 0;
	while (ft_is_printable(dico[i + j], 1) == 0 && dico[i + j] != '\n')
	{
		y = 0;
		while (dico[i + j + y] == ' ' && dico[i + j + y] != '\n')
			y++;
		if (dico[i + j + y] == '\n')
			break ;
		j++;
	}
	l = 0;
	tmpTab = malloc(sizeof(char) * (j + 1));
	if (!tmpTab)
		return (ft_free_struct(structTab, k));
	tmpTab[j] = '\0';
	while (l < j)
		tmpTab[l++] = dico[i++];
	structTab[k].name = tmpTab;
	return (i);
}

int	ft_parse_column(int i, char *dico)
{
	while (dico[i] != ':')
		if (dico[i++] != ' ')
			return (-1);
	while (ft_is_printable(dico[++i], 0) != 0)
	{
		if (dico[i] != ' ')
			return (-1);
	}
	return (i);
}

int	ft_parse_backspace(int i, char *dico)
{
	while (dico[i] != '\n' && dico[i] != '\0')
	{
		if (dico[i] != ' ')
			return (-1);
		i++;
	}
	return (i);
}
