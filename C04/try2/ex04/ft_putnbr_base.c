/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:42:19 by vchevill          #+#    #+#             */
/*   Updated: 2021/07/15 10:37:26 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(long int nbr, long int baselength, char *base)
{
	if (nbr >= baselength)
	{
		ft_print(nbr / baselength, baselength, base);
	}
	ft_putchar(base[nbr % baselength]);
}

long int	ft_negativ_number(long int nbr)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	return (nbr);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	baselength;
	long int	i;
	long int	nb;

	i = 0;
	baselength = 0;
	while (base[baselength] != '\0')
	{
		if (base[baselength] == '-' || base[baselength] == '+')
			return ;
		while (base[i] != '\0')
		{
			if (base[i] == base[baselength] && i != baselength)
				return ;
			i++;
		}
		i = 0;
		baselength++;
	}
	if (baselength <= 1)
		return ;
	nb = ft_negativ_number(nbr);
	ft_print(nb, baselength, base);
}
