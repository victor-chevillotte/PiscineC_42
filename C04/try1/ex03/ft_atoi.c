/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 19:17:43 by vchevill          #+#    #+#             */
/*   Updated: 2021/07/13 14:41:49 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_2(int i, int res, int sign, char *str)
{
	while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\v' || str [i] == '\f' || str[i] == '\r')
		&& str[i] != '\0')
		i ++;
	while ((str[i] == '+' || str[i] == '-') && str[i] != '\0')
	{
		if (str[i] == '+')
			sign = sign * 1;
		else if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 10 + str[i] - '0';
		else
			return (res * sign);
		i++;
	}
	return (res * sign);
}

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	i = 0;
	return (ft_atoi_2(i, res, sign, str));
}
