/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 09:33:49 by jmichel           #+#    #+#             */
/*   Updated: 2021/07/17 19:55:46 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

int	ft_verifPos(int **resTab, int x, int y, int sideLength)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < sideLength)
	{
		while (j < sideLength)
		{
			if (!(i == y && j == x) && (i == y || j == x))
			{
				if (resTab[i][j] == resTab[y][x])
					return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	ft_verif(int *inputTab, int **resTab, int *constxy, int sideLength)
{
	if (ft_verifPos(resTab, constxy[0], constxy[1], sideLength) == 0
		|| ft_verif_view(inputTab, resTab, constxy, sideLength) == 0)
		return (0);
	else
		return (1);
}
