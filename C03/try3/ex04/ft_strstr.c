/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 09:30:44 by vchevill          #+#    #+#             */
/*   Updated: 2021/07/12 11:18:22 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	i2;

	i = 0;
	i2 = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		while (str[i + i2] == to_find[i2] && str[i + i2] != '\0' )
			i2++;
		if (to_find[i2] == '\0')
			return (&str[i]);
		i++;
		i2 = 0;
	}
	return (0);
}
