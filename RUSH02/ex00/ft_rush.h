#ifndef FT_RUSH_H
# define FT_RUSH_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
typedef struct s_dicWord
{
	char	*nbr;
	char	*name;
	int		bol;
}				t_dicWord;
void				ft_putchar(char c);
void				ft_putstr(char *str);
int					ft_atoi(char *str);
char				*ft_strdup(char *src);
char				*ft_strdup_number(char *src);
int					ft_strlen(char *str);
int					ft_strlen_triple(char *str);
char				*ft_str_of_triple(char *str, int indexOfTriple);
int					ft_strcmp(char *s1, char *s2);
int					ft_is_printable(char c, int space);
t_dicWord			ft_div_max(char *nbr, t_dicWord *tab);
int					ft_recursive_read(char *str, t_dicWord *tab);
t_dicWord			ft_search(char *nbr, t_dicWord *tab);
char				*ft_putnbr(int nbr);
int					ft_checkargs(int argc, char **argv);
struct s_dicWord	*ft_parsing_main(char *pathfile);
int					ft_print_unit(int power, t_dicWord *tab,
						int indexMax, int i);
int					ft_check_dic(t_dicWord *tab);
char				*ft_file_read(char *path);
int					ft_free_struct(t_dicWord *structTab, int k);
int					ft_malloc_number(int k, t_dicWord *structTab,
						char *dico, int i);
int					ft_malloc_name(int k, t_dicWord *structTab,
						char *dico, int i);
int					ft_parse_column(int i, char *dico);
int					ft_parse_backspace(int i, char *dico);
int					ft_recursive_triples(char *str, int indexOfTriple,
						int maxIndexTriple, t_dicWord *tab);

#endif
