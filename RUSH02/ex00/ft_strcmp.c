int	ft_strcmp(char *s1, char *s2)
{
	int		i;
	int		u;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
		{
			u = s1[i] - s2[i];
			return (u);
		}
		else
		{
			i ++;
		}
	}
	return (0);
}
