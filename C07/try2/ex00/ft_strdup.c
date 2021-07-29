/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 08:53:10 by vchevill          #+#    #+#             */
/*   Updated: 2021/07/21 13:08:44 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
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
