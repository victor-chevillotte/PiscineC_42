/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 09:05:07 by vchevill          #+#    #+#             */
/*   Updated: 2021/07/13 10:32:05 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int unsigned	i;
	int unsigned	srclength;

	i = 0;
	srclength = 0;
	while (src[srclength] != '\0')
		srclength++;
	if (size == 0)
		return (srclength);
	while (i < size - 1 && src[i])
	{
		dest[i] = src [i];
		i++;
	}
	dest[i] = '\0';
	return (srclength);
}
