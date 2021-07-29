/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 12:43:56 by jmichel           #+#    #+#             */
/*   Updated: 2021/07/18 18:37:04 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUSH_H
# define FT_RUSH_H

# include <stdlib.h>
# include <unistd.h>

void	ft_putchar(char c);

int		ft_verif_view(int *inputTab, int **resTab,
			int *constxy, int sideLength);

int		**ft_putvalue(int *inputTab, int sideLength);

void	ft_display(int **resTab, int sideLength);

int		ft_recursive_backtracking(int**resTab, int sideLength, int *inputTab);

int		ft_verif(int *inputTab, int **resTab, int *constxy, int sideLength);

int		ft_check_exist(int **tab, int x, int y, int value);

int		ft_putObviousValue(int **resTab, int l, int *inputTab);

void	ft_print_error(void);

#endif
