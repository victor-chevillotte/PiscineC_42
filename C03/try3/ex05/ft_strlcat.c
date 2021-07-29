/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 09:54:29 by vchevill          #+#    #+#             */
/*   Updated: 2021/07/12 14:02:47 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int unsigned	i;
	int				i2;
	int				i3;

	i = 0;
	i2 = 0;
	i3 = 0;
	if (size == 0)
		return (0);
	while (dest[i] != '\0')
		i ++;
	while (src[i3] != '\0')
		i3++;
	while (src[i2] != '\0' && (i < size - 1 && size != 0))
	{
		dest[i] = src [i2];
		i++;
		i2++;
	}
	dest[i] = '\0';
	if (i >= size - 1)
		return (i3 + size);
	else
		return (i);
}
