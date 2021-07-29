/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberthoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 11:02:15 by mberthoi          #+#    #+#             */
/*   Updated: 2021/07/10 11:10:02 by mberthoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	draw_line(int x, int y, int ix, int iy)
{
	if ((ix == 0 && iy == 0) || (ix == 0 && iy == y - 1))
		ft_putchar('A');
	else if ((iy == 0 && ix == x - 1) || (iy == y - 1 && ix == x - 1))
		ft_putchar('C');
	else if (ix != 0 && ix != x - 1 && iy != y - 1 && iy != 0)
		ft_putchar(' ');
	else
		ft_putchar('B');
}

void	draw(int x, int y)
{
	int	ix;
	int	iy;

	ix = 0;
	iy = 0;
	while (iy < y)
	{
		while (ix < x)
		{
			draw_line(x, y, ix, iy);
			ix++;
		}
		ft_putchar('\n');
		ix = 0;
		iy++;
	}
}

void	rush(int x, int y)
{
	if (x <= 0 || y <= 0)
	{
		write(2, "La taille ne peut pas etre inferieure a 1\n", 41);
	}
	else
	{
		draw(x, y);
	}
}
