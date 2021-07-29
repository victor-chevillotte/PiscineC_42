/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 18:12:54 by vchevill          #+#    #+#             */
/*   Updated: 2021/07/17 19:38:13 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

int	ft_checkParams(int argc, char **argv)
{
	int	i;
	int	clength;

	i = 0;
	clength = 0;
	if (argc != 2)
	{
		ft_print_error();
		return (-1);
	}
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] != ' ' && !(argv[1][i] >= '0' && argv[1][i] <= '9'))
		{
			ft_print_error();
			return (-1);
		}
		if (argv[1][i] != ' ')
			clength++;
		i++;
	}
	return (clength);
}

int	*ft_entryParsing_2(char *c, int clength, int *tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (c[i] != '\0')
	{
		if (c[i] != 32)
		{
			tab[j] = c[i] - 48;
			j++;
		}
		i++;
	}
	i = 0;
	while (c[i++] != '\0')
	{
		if (c[i] - 48 > clength / 4)
		{
			ft_print_error();
			tab[0] = -1;
			return (tab);
		}
	}
	return (tab);
}

int	*ft_entryParsing(char *c, int clength)
{
	int	*tab;

	tab = (int *)malloc(sizeof(int) * clength);
	if (clength <= 0)
	{
		ft_print_error();
		tab[0] = -1;
		return (tab);
	}
	if (clength % 4 != 0)
	{
		ft_print_error();
		tab[0] = -1;
		return (tab);
	}
	return (ft_entryParsing_2(c, clength, tab));
}

void	ft_display(int **resTab, int sideLength)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < sideLength)
	{
		while (j < sideLength)
		{
			ft_putchar((char)(resTab[i][j] + 48));
			if (j != sideLength - 1)
				ft_putchar(' ');
			j++;
		}
		j = 0;
		ft_putchar('\n');
		i ++;
	}
}

int	main(int argc, char **argv)
{
	int	clength;
	int	sideLength;
	int	*inputTab;
	int	**resTab;

	clength = ft_checkParams(argc, argv);
	if (clength == -1)
		return (1);
	sideLength = clength / 4;
	inputTab = ft_entryParsing(argv[1], clength);
	if (inputTab[0] == -1)
		return (1);
	resTab = ft_putvalue (inputTab, sideLength);
	if (resTab[0][0] != -1)
		ft_display(resTab, sideLength);
	else
		ft_print_error();
	free(resTab);
	return (0);
}
