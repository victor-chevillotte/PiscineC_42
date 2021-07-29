/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 11:05:12 by vchevill          #+#    #+#             */
/*   Updated: 2021/07/19 10:05:13 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	get_pos(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	checkbase(char *base)
{
	int	i;
	int	baselength;

	baselength = 0;
	i = 0;
	while (base[baselength] != '\0')
	{
		if (base[baselength] == '-' || base[baselength] == '+'
			|| (base[baselength] >= 9 && base[baselength] <= 13)
			|| base[baselength] == ' ')
			return (0);
		while (base[i] != '\0')
		{
			if (base[i] == base[baselength] && i != baselength)
				return (0);
			i++;
		}
		i = 0;
		baselength++;
	}
	return (baselength);
}

long int	check_spaces(char *str)
{
	long int	i;

	i = 0;
	while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\v' || str [i] == '\f' || str[i] == '\r')
		&& str[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi_base_2(long int res, long int sign, char *str, char *base)
{
	long int	i;
	long int	baselength;

	i = check_spaces(str);
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '+')
			sign = sign * 1;
		else if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	baselength = checkbase(base);
	if (baselength == 0)
		return (0);
	while (str[i] != '\0' && get_pos(base, str[i]) != -1)
	{
		if (get_pos(base, str[i]) == -1)
			return (res * sign);
		res = res * baselength + get_pos(base, str[i]);
		i++;
	}
	return (res * sign);
}

int	ft_atoi_base(char *str, char *base)
{
	long int	i;
	long int	res;
	long int	sign;
	long int	baselength;

	res = 0;
	sign = 1;
	i = 0;
	baselength = 0;
	return (ft_atoi_base_2(res, sign, str, base));
}
int main ()
{
	char b[] = "     \n\r\t\v\f+----+-opyeyinovp";
	char a[] = "poneyvif";

	printf("Expected output: a recuperer sur le site jalu.ch (cf. Notion)\n");
	printf("Output: %i\n",ft_atoi_base(b,a));
}
