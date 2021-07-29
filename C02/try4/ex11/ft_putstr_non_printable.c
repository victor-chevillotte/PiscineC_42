/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 16:17:20 by vchevill          #+#    #+#             */
/*   Updated: 2021/07/13 15:27:09 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char *c)
{
	write(1, &c, 1);
}

void	ft_hex(int c)
{
	char	*b;

	b = "0123456789abcdef";
	ft_putchar(&b[c / 16]);
	ft_putchar(&b[c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 0)
			str[i] += 256;
		if (str[i] >= 32 && str[i] <= 126)
		{
			ft_putchar(&str[i]);
		}
		else
		{
			ft_putchar("\\");
			ft_hex(str[i]);
		}
		i++;
	}
}
