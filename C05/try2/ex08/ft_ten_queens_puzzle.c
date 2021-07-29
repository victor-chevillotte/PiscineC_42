/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 16:14:08 by vchevill          #+#    #+#             */
/*   Updated: 2021/07/27 11:32:37 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

int	ft_solve(char *tab, int nbq, int nbsol)
{
	int	i;
	int	j;

	if (nbq == 10)
	{
		nbq = 0;
		while (nbq < 10)
			ft_putchar(tab[nbq++] + '0');
		ft_putchar('\n');
		nbsol++;
		return (nbsol);
	}
	i = -1;
	while (++i < 10)
	{
		j = 0;
		while (j < nbq && i != tab[j] && ft_abs(tab[j] - i) != nbq - j)
			j++;
		if (j >= nbq)
		{
			tab[nbq] = i;
			nbsol = ft_solve(tab, nbq + 1, nbsol);
		}
	}
	return (nbsol);
}

int	ft_ten_queens_puzzle(void)
{
	char	tab[10];
	int		nbqueens;

	nbqueens = 0;
	return (ft_solve(tab, nbqueens, 0));
}
