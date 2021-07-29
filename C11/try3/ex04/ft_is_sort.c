/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 09:49:34 by vchevill          #+#    #+#             */
/*   Updated: 2021/07/29 14:10:43 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
		{
			status = 1;
			break ;
		}
		i++;
	}
	i = length - 1;
	if (status == 1)
	{
		while (i > 0)
		{
			if (f(tab[i], tab[i - 1]) > 0)
				return (0);
			i--;
		}
	}
	return (1);
}
