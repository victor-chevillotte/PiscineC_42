/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 10:09:46 by vchevill          #+#    #+#             */
/*   Updated: 2021/07/22 10:09:48 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
int	ft_is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	if (c == '\0')
		return (1);
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_is_charset(str[i], charset) == 0
			&& ft_is_charset(str[i + 1], charset) == 1)
		{
			count ++;
		}
		i++;
	}
	return (count);
}

int	ft_end_of_word(int ind_start, char *str, char *charset)
{
	int	i;

	i = ind_start;
	while (ft_is_charset(str[i + 1], charset) != 1)
		i++;
	return (i);
}

char	**ft_split_words(char *str, char *charset, char **resTab)
{
	int		i;
	int		endWord;
	char	*resWord;
	int		k;
	int		j;

	i = -1;
	k = 0;
	j = 0;
	while (str[++i] != '\0')
	{
		if (ft_is_charset(str[i], charset) == 0)
		{
			endWord = ft_end_of_word(i, str, charset);
			resWord = (char *)malloc(sizeof(char) * (endWord - i + 2));
			if (!resWord)
				return (NULL);
			while (i <= endWord)
				resWord[j++] = str[i++];
			resWord[j] = '\0';
			resTab[k++] = resWord;
			j = 0;
		}
	}
	return (resTab);
}

char	**ft_split(char *str, char *charset)
{	
	char	**resTab;
	int		nbr_words;

	nbr_words = ft_count_words(str, charset) + 1;
	resTab = (char **)malloc(sizeof(char *) * nbr_words);
	if (!resTab)
		return (NULL);
	resTab = ft_split_words(str, charset, resTab);
	resTab[nbr_words - 1] = 0;
	return (resTab);
}
