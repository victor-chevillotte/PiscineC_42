/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 17:18:38 by vchevill          #+#    #+#             */
/*   Updated: 2021/07/07 17:31:39 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
void	ft_is_negative(int n)
{
	if (n < 0)
	{
		write(1, "N", 1);
	}	
	else
	{
		write(1, "P", 1);
	}
}
