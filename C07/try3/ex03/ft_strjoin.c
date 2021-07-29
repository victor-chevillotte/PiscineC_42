/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 10:21:27 by vchevill          #+#    #+#             */
/*   Updated: 2021/07/21 13:09:03 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
int	ft_strlen(char **strs, char *sep, int size)
{
	int	i;
	int	j;
	int	tabLen;
	int	sepLen;

	i = 0;
	j = 0;
	tabLen = 0;
	sepLen = 0;
	while (i < size)
	{
		while (strs[i][j++] != '\0')
			tabLen++;
		i++;
		j = 0;
	}
	i = 0;
	while (sep[i] != '\0')
	{
		i++;
		sepLen++;
	}
	return (tabLen + sepLen * (size - 1) + 1);
}

char	*ft_declare_tab(int size, char **strs, char *sep)
{
	char	*tab;

	if (size <= 0)
	{
		tab = (char *)malloc(sizeof(char));
		if (!tab)
			return (NULL);
		return (tab);
	}
	tab = (char *)malloc(sizeof(char) * ft_strlen(strs, sep, size));
	if (!tab)
		return (NULL);
	return (tab);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*tab;
	int		i;
	int		j;
	int		strsLen;

	i = 0;
	strsLen = 0;
	tab = ft_declare_tab(size, strs, sep);
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			tab[strsLen++] = strs[i][j++];
		j = 0;
		while (sep[j] != '\0' && (i < size - 1))
			tab[strsLen++] = sep[j++];
		i++;
	}
	tab[strsLen] = '\0';
	return (tab);
}
