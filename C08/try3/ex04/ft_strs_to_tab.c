/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 10:23:21 by vchevill          #+#    #+#             */
/*   Updated: 2021/07/21 11:30:06 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		srclength;
	int		i;
	char	*dest;

	srclength = 0;
	i = 0;
	while (src[srclength] != '\0')
		srclength++;
	dest = (char *)malloc(sizeof(char) * (srclength + 1));
	if (!dest)
		return (NULL);
	while (i < srclength)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
	{
		length ++;
	}
	return (length);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*resTab;

	i = 0;
	resTab = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!resTab)
		return (NULL);
	while (i < ac)
	{
		resTab[i].size = ft_strlen(av[i]);
		resTab[i].str = av[i];
		resTab[i].copy = ft_strdup(av[i]);
		if (!resTab[i].str || !resTab[i].copy)
		{
			free (resTab);
			return (NULL);
		}
		i++;
	}
	resTab[i].str = 0;
	return (resTab);
}
