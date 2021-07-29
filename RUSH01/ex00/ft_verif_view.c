/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_view.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 13:57:44 by vchevill          #+#    #+#             */
/*   Updated: 2021/07/18 14:08:07 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

int	ft_verif_row_2(int *tab, int countviewright, int len)
{
	int	i;
	int	count;
	int	max;

	i = len - 1;
	count = 1;
	max = tab[i];
	while (i > 0)
	{
		if (tab[i] == 0 || tab[i - 1] == 0)
			return (1);
		else if (max - tab[i - 1] < 0)
		{
			count++;
			max = tab [i - 1];
		}
		if (max == len)
			break ;
		i--;
	}
	if (countviewright != count)
		return (0);
	return (1);
}

int	ft_verif_row(int *tab, int countviewleft, int countviewright, int len)
{
	int	i;
	int	count;
	int	max;

	i = 0;
	count = 1;
	max = tab[i];
	while (i < len - 1)
	{
		if (tab[i] == 0 || tab[i + 1] == 0)
			return (1);
		else if (max - tab[i + 1] < 0)
		{
			max = tab [i + 1];
			count++;
		}
		if (max == len)
			break ;
		i++;
	}
	if (countviewleft != count)
		return (0);
	return (ft_verif_row_2(tab, countviewright, len));
}

int	*ft_verif_column(int **tab, int x, int size)
{
	int	*result;
	int	i;

	i = 0;
	result = malloc(size * sizeof(int));
	while (i < size)
	{
		result[i] = tab[i][x];
		i++;
	}
	i = 0;
	return (result);
}

int	ft_verif_view(int *inputTab, int **resTab, int *constxy, int sideLength)
{
	if (ft_verif_row(ft_verif_column(resTab, constxy[0], sideLength),
			inputTab[constxy[0]], inputTab[constxy[0] + sideLength],
			sideLength) == 1 && ft_verif_row(resTab[constxy[1]],
			inputTab[2 * sideLength + constxy[1]],
			inputTab[3 * sideLength + constxy[1]], sideLength) == 1)
		return (1);
	return (0);
}
