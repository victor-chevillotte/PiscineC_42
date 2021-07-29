/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 09:47:23 by vchevill          #+#    #+#             */
/*   Updated: 2021/07/29 09:41:54 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_OP_H
# define FT_OP_H

# include "unistd.h"

typedef enum e_op
{
	sum_operator,
	div_operator,
	multipl_operator,
	mod_operator,
	sub_operator,
	null_operator
}					t_operator;

void	ft_putchar(char c);

void	ft_putstr(char *str);

void	ft_mod(int a, int b);

void	ft_div(int a, int b);

void	ft_multipl(int a, int b);

void	ft_sub(int a, int b);

void	ft_sum(int a, int b);

int		ft_atoi(char *str);

void	ft_putnbr(int nb);
#endif
