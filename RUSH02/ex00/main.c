#include "ft_rush.h"

char	**ft_parse_params(int argc, char **argv)
{
	char	**inputTab;

	inputTab = malloc(sizeof(char *) * 2);
	if (!inputTab)
	{
		ft_putstr("Error\n");
		return (NULL);
	}
	if (argc == 3)
	{
		inputTab[0] = ft_strdup(argv[1]);
		inputTab[1] = ft_strdup_number(argv[2]);
	}
	else if (argc == 2)
	{	
		inputTab[0] = ft_strdup("numbers.dict");
		inputTab[1] = ft_strdup_number(argv[1]);
	}
	return (inputTab);
}

void	ft_free_inputTab(char **inputTab)
{
	free(inputTab[0]);
	free(inputTab[1]);
	free(inputTab);
}

int	main(int argc, char **argv)
{
	char		**inputTab;
	t_dicWord	*dico;

	if (ft_checkargs(argc, argv) == -1)
		return (1);
	inputTab = ft_parse_params(argc, argv);
	if (!inputTab)
		return (1);
	dico = ft_parsing_main(inputTab[0]);
	if (!dico)
		return (1);
	if (ft_check_dic(dico) == 1)
		return (1);
	if (ft_recursive_read(inputTab[1], dico) == 1)
		return (1);
	ft_free_struct(dico, -1);
	ft_free_inputTab(inputTab);
	free(dico);
	return (0);
}
