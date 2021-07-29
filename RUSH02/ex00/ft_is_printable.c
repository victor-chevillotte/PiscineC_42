int	ft_is_printable(char c, int space)
{
	if (c == '\0')
		return (1);
	if (space == 0)
	{
		if (c < 33 || c == 127)
			return (1);
	}
	else if (space == 1)
	{
		if (c < 32 || c == 127)
			return (1);
	}
	return (0);
}
