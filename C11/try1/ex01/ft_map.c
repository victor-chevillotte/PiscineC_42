/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 09:13:58 by vchevill          #+#    #+#             */
/*   Updated: 2021/07/29 09:45:55 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	*resTab;
	int	i;

	resTab = (int *)malloc(sizeof(int) * length);
	if (length < 1 || !resTab)
		return (NULL);
	i = 0;
	while (i < length)
	{
		resTab[i] = f(tab[i]);
		i++;
	}
	return (resTab);
}
