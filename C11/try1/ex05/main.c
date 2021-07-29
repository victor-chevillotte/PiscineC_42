#include "ft_op.h"
t_operator	ft_get_op_function(char *str)
{
	if (!str || str[1])
		return (null_operator);
	if (*str == '*')
		return (multipl_operator);
	if (*str == '/')
		return (div_operator);
	if (*str == '+')
		return (sum_operator);
	if (*str == '-')
		return (sub_operator);
	if (*str == '%')
		return (mod_operator);
	return (null_operator);
}

int	main(int argc, char **argv)
{
	void		(*operations[5])(int, int);
	t_operator	whichop;

	operations[multipl_operator] = &ft_multipl;
	operations[div_operator] = &ft_div;
	operations[sum_operator] = &ft_sum;
	operations[sub_operator] = &ft_sub;
	operations[mod_operator] = &ft_mod;
	if (argc != 4)
		return (0);
	whichop = ft_get_op_function(argv[2]);
	if (whichop == null_operator)
		ft_putnbr(0);
	else
		operations[whichop](ft_atoi(argv[1]), ft_atoi(argv[3]));
	ft_putchar('\n');
	return (0);
}
