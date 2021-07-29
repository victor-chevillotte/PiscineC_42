/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvalue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 09:32:37 by vchevill          #+#    #+#             */
/*   Updated: 2021/07/18 18:40:27 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

int	**ft_mallocEmptyTab(int sideLength)
{
	int	**resTab;
	int	*lignTab;
	int	i;
	int	j;

	i = 0;
	j = 0;
	resTab = (int **)malloc(sizeof(int *) * sideLength);
	while (i < sideLength)
	{
		lignTab = (int *)malloc(sizeof(int) * sideLength);
		resTab[i] = lignTab;
		while (j < sideLength)
		{
			resTab[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
	return (resTab);
}

int	ft_check_exist(int **tab, int x, int y, int value)
{
	if (tab[x][y] == 0 || tab[x][y] == value)
	{
		tab[x][y] = value;
		return (0);
	}
	else
		return (1);
}

int	*ft_rec_b_2(int**resTab, int sideLength, int *inputTab, int *constxy)
{
	while (constxy[2] <= sideLength)
	{
		resTab[constxy[1]][constxy[0]] = constxy[2];
		if (ft_verif(inputTab, resTab, constxy, sideLength) == 1)
		{
			if (ft_recursive_backtracking(resTab, sideLength, inputTab))
			{
				constxy[3] = 1;
				return (constxy);
			}
			resTab[constxy[1]][constxy[0]] = 0;
		}
		constxy[2]++;
		if (constxy[2] > sideLength)
		{
			resTab[constxy[1]][constxy[0]] = 0;
			constxy[3] = 0;
			return (constxy);
		}
	}
	constxy[3] = 2;
	return (constxy);
}

int	ft_recursive_backtracking(int**resTab, int sideLength, int *inputTab)
{
	int	*constxy;

	constxy = (int *)malloc(sizeof(int) * sideLength);
	constxy[0] = 0;
	constxy[1] = 0;
	constxy[2] = 1;
	constxy[3] = 1;
	while (constxy[1] < sideLength)
	{
		while (constxy[0] < sideLength)
		{	
			if (resTab[constxy[1]][constxy[0]] == 0)
			{
				constxy[2] = 1;
				constxy = ft_rec_b_2(resTab, sideLength, inputTab, constxy);
				if (constxy[3] != 2)
					return (constxy[3]);
			}
			constxy[0]++;
		}
		constxy[0] = 0;
		constxy[1]++;
	}
	free(constxy);
	return (1);
}

int	**ft_putvalue(int *inputTab, int sideLength)
{
	int	**resTab;

	resTab = ft_mallocEmptyTab(sideLength);
	if (ft_putObviousValue(resTab, sideLength, inputTab) == 0)
		resTab[0][0] = -1;
	if (ft_recursive_backtracking(resTab, sideLength, inputTab) == 0)
		resTab[0][0] = -1;
	return (resTab);
}
