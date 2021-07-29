/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 10:38:33 by vchevill          #+#    #+#             */
/*   Updated: 2021/07/08 16:56:38 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h> 

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_combn(int n)
{
	int	tab [9];
	int	i;

	i = 0;
	 while (tab[0] != 10 - n)
	{
		while (tab[n - 1 - i] < 9 - i)
		{
			tab[n - 1]++;
			ft_putchar(tab[0] + 48);
			ft_putchar(tab[1] + '0');
			write (1, ",", 1);
			write (1, " ", 1);
		}
		i ++;
		tab[n - 1 - i]++;
		tab[n - 1]++;
	}
}
