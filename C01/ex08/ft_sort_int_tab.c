/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 14:32:04 by vchevill          #+#    #+#             */
/*   Updated: 2021/07/10 17:40:26 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = tab[0];
	while (i < size)
	{
		if (tab[i] < tab[i - 1] && i > 0)
		{
			tmp = tab[i - 1];
			tab[i - 1] = tab [i];
			tab[i] = tmp;
			i = 0;
		}
		else
		{
			i++;
		}
	}
}
