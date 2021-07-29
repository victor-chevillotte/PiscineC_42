/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 08:19:43 by jmichel           #+#    #+#             */
/*   Updated: 2021/07/18 18:22:32 by jmichel          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

int	ft_replace(int **resTab, int l, int j, int i)
{
	int	k;

	k = 0;
	while (k < l)
	{
		if (ft_check_exist(resTab, (l - 1) * j + k * (1 - j) - k * (j),
				i % l, k + 1))
			return (1);
		k++;
	}
	return (0);
}

int	ft_putObviousValue2(int **resTab, int l, int *inputTab, int i)
{
	int	j;

	j = 0;
	while (i < l * 4)
	{
		if (i == l * 3)
			j = 1;
		if (inputTab[i] == 1)
		{
			if (ft_check_exist(resTab, i % l, (l - 1) * j, l))
				return (0);
		}
		else if (inputTab[i] == l)
		{
			if (ft_replace(resTab, i % l, (l - 1) * j, i))
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_putObviousValue(int **resTab, int l, int *inputTab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < l * 2)
	{
		if (i == l)
			j = 1;
		if (inputTab[i] == 1)
		{
			if (ft_check_exist(resTab, (l - 1) * j, i % l, l))
				return (0);
		}
		else if (inputTab[i] == l)
		{
			if (ft_replace(resTab, l, j, i))
				return (0);
		}
		i++;
	}
	return (ft_putObviousValue2(resTab, l, inputTab, i));
}
