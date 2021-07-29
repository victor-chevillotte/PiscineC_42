#include "ft_rush.h"

struct	s_dicWord	*ft_mallocTab(char *dico)
{
	int			i;
	int			count;
	t_dicWord	*structTab;

	i = 0;
	count = 1;
	while (dico[i] != '\0')
	{
		if (dico[i] == '\n')
			count++;
		i++;
	}
	structTab = malloc(sizeof(t_dicWord) * (count + 1));
	if (!structTab)
		return (NULL);
	return (structTab);
}

int	ft_free_struct(t_dicWord *structTab, int k)
{
	int	i;

	i = 0;
	if (k != -1)
	{
		while (i <= k)
		{
			free(structTab[i].nbr);
			free(structTab[i].name);
			i++;
		}
	}
	else
	{
		while (structTab[i].name != 0)
		{
			free(structTab[i].nbr);
			free(structTab[i].name);
			i++;
		}
	}

	return (-1);
}

struct s_dicWord	*ft_parsing(char *dico, int k)
{
	int			i;
	t_dicWord	*structTab;

	i = -1;
	structTab = ft_mallocTab(dico);
	if (!structTab)
		return (NULL);
	while (dico[++i] != '\0')
	{
		i = ft_malloc_number(++k, structTab, dico, i);
		if (i == -1)
			return (NULL);
		i = ft_parse_column(i, dico);
		if (i == -1)
			return (NULL);
		i = ft_malloc_name(k, structTab, dico, i);
		if (i == -1)
			return (NULL);
		i = ft_parse_backspace(i, dico);
		if (i == -1)
			return (NULL);
	}
	structTab[++k].name = 0;
	return (structTab);
}

struct	s_dicWord	*ft_parsing_main(char *pathfile)
{
	char		*content;
	t_dicWord	*dico;

	content = ft_file_read(pathfile);
	dico = ft_parsing(content, -1);
	if (!dico)
		ft_putstr("Dict Error\n");
	return (dico);
	free (content);
}
