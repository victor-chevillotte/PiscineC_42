#include "ft_rush.h"

char	*ft_strdup_number2(int srclength, int count, char *dest, char *src)
{
	int	i;

	i = 0;
	if (srclength == 0)
	{
		dest[0] = '\0';
	}
	else
	{
		while (i < srclength)
		{
			dest[i] = src[i + count];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}

char	*ft_strdup_number(char *src)
{
	int		srclength;
	int		i;
	char	*dest;
	int		count;

	srclength = 0;
	count = 0;
	i = 0;
	while (src[i] != '\0')
	{
		srclength++;
		if (srclength == 1 && src[i] == '0')
		{
			count++;
			srclength--;
		}
		i++;
	}
	if (srclength == 0)
		dest = (char *)malloc(sizeof(char) * (srclength + 1));
	else
		dest = (char *)malloc(sizeof(char) * (srclength + 1));
	if (!dest)
		return (NULL);
	return (ft_strdup_number2(srclength, count, dest, src));
}

char	*ft_strdup(char *src)
{
	int		srclength;
	int		i;
	char	*dest;

	srclength = 0;
	i = 0;
	while (src[srclength] != '\0')
		srclength++;
	dest = (char *)malloc(sizeof(char) * (srclength + 1));
	if (!dest)
		return (NULL);
	while (i < srclength)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
