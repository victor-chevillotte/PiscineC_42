/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 16:46:10 by vchevill          #+#    #+#             */
/*   Updated: 2021/07/15 11:47:06 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	tmp;

	i = 1;
	tmp = nb;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (i < tmp)
	{
		nb *= i;
		i++;
	}
	return (nb);
}
