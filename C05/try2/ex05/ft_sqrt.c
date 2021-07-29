/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 08:28:12 by vchevill          #+#    #+#             */
/*   Updated: 2021/07/15 16:29:26 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long int	i;

	i = 1;
	if (nb < 1)
		return (0);
	while (i * i < nb && i < 46340)
		i++;
	if (i * i == nb)
		return (i);
	else
		return (0);
}