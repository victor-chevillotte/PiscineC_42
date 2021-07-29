/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 13:28:13 by vchevill          #+#    #+#             */
/*   Updated: 2021/07/29 14:37:28 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
int	ft_atoi_base(char *str, char *base);
int	checkbase(char *base);

int	ft_memory(long int nbr, long int baselength, char *base, int count)
{
	if (nbr < 0)
		nbr *= -1;
	if (nbr >= baselength)
	{
		count ++;
		count = ft_memory(nbr / baselength, baselength, base, count);
	}
	return (count);
}

char	*ft_res_in_tab(long int nbr, long int baselength,
		char *base, int memorySize)
{
	int		i;
	char	*resTab;
	int		sign;

	resTab = (char *)malloc(sizeof(char) * memorySize);
	sign = 0;
	i = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		sign = 1;
		resTab[i] = '-';
	}
	while (i < memorySize - 1 - sign)
	{
		resTab[memorySize - 2 - i++] = base[nbr % baselength];
		if (nbr >= baselength)
			nbr = nbr / baselength;
	}
	resTab[memorySize - 1] = '\0';
	return (resTab);
}

char	*ft_negativ_number(long int nb, long int baseLength, char *base)
{
	int		memorySize;
	int		sign;

	sign = 0;
	if (nb < 0)
	{
		sign = 1;
	}
	memorySize = ft_memory(nb, baseLength, base, 1 + sign) + 1;
	return (ft_res_in_tab(nb, baseLength, base, memorySize));
}

char	*ft_putnbr_base(int nbr, char *base)
{
	long int	baselength;
	long int	i;

	i = 0;
	baselength = 0;
	while (base[baselength] != '\0')
	{
		if (base[baselength] == '-' || base[baselength] == '+')
			return (NULL);
		while (base[i] != '\0')
		{
			if (base[i] == base[baselength] && i != baselength)
				return (NULL);
			i++;
		}
		i = 0;
		baselength++;
	}
	if (baselength <= 1)
		return (NULL);
	return (ft_negativ_number(nbr, baselength, base));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	nb;

	if (checkbase(base_from) < 2 || checkbase(base_to) < 2)
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	return (ft_putnbr_base(nb, base_to));
}
