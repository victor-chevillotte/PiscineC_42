#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strlen_triple(char *str)
{
	int	triple;

	triple = (ft_strlen(str) / 3);
	if ((ft_strlen(str) % 3) != 0)
		triple += 1;
	return (triple);
}

char	*ft_str_of_triple(char *str, int indexOfTriple)
{
	int		i;
	int		j;
	int		k;
	int		nbchar;
	char	*nb;

	i = 0;
	j = 0;
	k = 0;
	nb = (char *)malloc(sizeof(char) * 4);
	if (!nb)
		return (NULL);
	nbchar = ft_strlen(str);
	while ((nbchar + j) % 3 != 0)
		 j++;
	if (indexOfTriple == 0)
		k = j;
	while (i < (3 - k))
	{
		nb[i] = str[(3 * indexOfTriple) + i - j + k];
		i++;
	}
	nb[i] = '\0';
	return (nb);
}
