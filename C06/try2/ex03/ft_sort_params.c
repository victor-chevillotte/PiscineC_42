/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 18:46:13 by vchevill          #+#    #+#             */
/*   Updated: 2021/07/15 18:24:43 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		while (argv[i][j] != '\0')
			ft_putchar(argv[i][j++]);
		ft_putchar('\n');
		j = 0;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*c;

	i = 1;
	j = 0;
	while (i < argc - 1)
	{
		while (argv[i][j] == argv[i + 1][j] && argv[i][j] != '\0')
			j++;
		if (argv[i][j] > argv[i + 1][j])
		{
			c = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = c;
			i = 0;
		}
		j = 0;
		i++;
	}
	ft_print(argc, argv);
}
