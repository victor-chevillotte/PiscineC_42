/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 12:27:53 by vchevill          #+#    #+#             */
/*   Updated: 2021/07/08 11:47:14 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2_2(int a, int b)
{
	ft_putchar(a / 10 + 48);
	ft_putchar(a % 10 + 48);
	write(1, " ", 1);
	ft_putchar(b / 10 + 48);
	ft_putchar(b % 10 + 48);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (a <= 98 )
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_print_comb2_2(a, b);
			if (b != 99 || a != 98)
			{
				write(1, ",", 1);
				write(1, " ", 1);
			}
			b ++;
		}
		a ++;
	}
}
