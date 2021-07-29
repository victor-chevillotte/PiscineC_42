/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 09:54:29 by vchevill          #+#    #+#             */
/*   Updated: 2021/07/14 10:27:28 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
unsigned int	ft_str_length(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i ++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	i2;
	unsigned int	srclength;
	unsigned int	destlength;

	i = 0;
	srclength = ft_str_length(src);
	destlength = ft_str_length(dest);
	i2 = destlength;
	if (size == 0 || size < destlength)
		return (srclength + size);
	while (src[i] != '\0' && i2 < size - 1 )
	{
		dest[i2] = src[i];
		i++;
		i2++;
	}
	dest[i2] = '\0';
	return (srclength + destlength);
}
