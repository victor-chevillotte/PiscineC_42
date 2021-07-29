/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 17:44:51 by vchevill          #+#    #+#             */
/*   Updated: 2021/07/19 08:20:55 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	char	*name;
	int		i;

	i = 0;
	argc = 2;
	name = argv[0];
	while (name[i] != '\0')
	{
		ft_putchar(name[i]);
		i++;
	}
	ft_putchar('\n');
}
