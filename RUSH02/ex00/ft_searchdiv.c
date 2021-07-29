/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_searchdiv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajossera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 20:47:00 by ajossera          #+#    #+#             */
/*   Updated: 2021/07/25 21:17:39 by ajossera         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "ft_rush.h"

char	*ft_compsup(char *str, char *str2)
{	
	if (ft_strlen(str) > ft_strlen(str2))
		return (str);
	if (ft_strlen(str2) > ft_strlen(str))
		return (str2);
	if (ft_strcmp(str, str2) > 0)
		return (str);
	if (ft_strcmp(str2, str) > 0)
		return (str2);
	return ("0");
}

t_dicWord	ft_div_max(char *nbr, t_dicWord *tab)
{
	int			i;
	t_dicWord	b;

	b.nbr = "0";
	i = 0;
	while (tab[i].name)
	{
		if (ft_compsup(tab[i].nbr, b.nbr) == tab[i].nbr
			&& tab[i].bol == 0
			&& ((ft_compsup(tab[i].nbr, nbr) == nbr)
				|| ft_strcmp(ft_compsup(tab[i].nbr, nbr), "0") == 0))
		{
			b.nbr = tab[i].nbr;
			b.name = tab[i].name;
		}
		i++;
	}
	return (b);
}

t_dicWord	ft_search(char *nbr, t_dicWord *tab)
{
	int					i;

	i = 0;
	tab[i].nbr = "-1";
	while (tab[i].name)
	{
		if (ft_strcmp(tab[i].nbr, nbr) == 0)
		{
			return (tab[i]);
		}
		i++;
	}
	return (tab[i]);
}
