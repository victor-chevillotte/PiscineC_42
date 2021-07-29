/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 09:27:47 by vchevill          #+#    #+#             */
/*   Updated: 2021/07/29 09:38:35 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
void	ft_swap(char **a, char **b)
{
	char	*c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
{
	int	size;
	int	i;

	size = 0;
	while (tab[size] != '\0')
		size++;
	while (--size >= 0)
	{
		i = 0;
		while (++i <= size)
			if (cmp(tab[i - 1], tab [i]) > 0)
				ft_swap(&tab[i - 1], &tab[i]);
	}
}
