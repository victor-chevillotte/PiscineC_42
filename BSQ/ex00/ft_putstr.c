#include "ft_header.h"

void	ft_putstr(char *str, int exit)
{
	while (*str)
	{
		ft_putchar(*str, exit);
		str++;
	}
}
