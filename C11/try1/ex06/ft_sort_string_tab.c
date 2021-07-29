/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 18:32:09 by vchevill          #+#    #+#             */
/*   Updated: 2021/07/29 09:41:04 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **a, char **b)
{
	char	*c;

	c = *a;
	*a = *b;
	*b = c;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0' || s2[i] == '\0')
		{
			return (0);
		}
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_sort_string_tab2(char **tab, int size)
{
	char	*tmp;
	int		i;
	int		j;

	if (size < 2)
		return ;
	tmp = tab [--size];
	i = 0;
	j = -1;
	while (++j < size)
	{
		if (ft_strcmp(tab[j], tmp) < 0)
			ft_swap(&tab[i++], &tab[j]);
		if (ft_strcmp(tab[i], tab[size]) > 0)
			ft_swap(&tab[i], &tab[size]);
		ft_sort_string_tab2(tab, i);
		ft_sort_string_tab2(tab + i + 1, size - i);
	}
}

void	ft_sort_string_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	ft_sort_string_tab2(tab, i);
}
