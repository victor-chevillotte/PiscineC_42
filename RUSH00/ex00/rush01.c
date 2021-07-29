/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 10:57:27 by vchevill          #+#    #+#             */
/*   Updated: 2021/07/10 11:07:54 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	draw_line(int x, int y, int ix, int iy)
{
	if (ix == 0 && iy == 0)
		ft_putchar('/');
	else if (ix == x - 1 && iy == 0)
		ft_putchar('\\');
	else if (ix == 0 && iy == y - 1)
		ft_putchar('\\');
	else if (ix == x - 1 && iy == y - 1)
		ft_putchar('/');
	else if (ix != 0 && ix != x - 1 && iy != y - 1 && iy != 0)
		ft_putchar(' ');
	else
		ft_putchar('*');
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
