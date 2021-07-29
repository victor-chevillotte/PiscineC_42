#ifndef FT_HEADER_H
# define FT_HEADER_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# define ABS(x) (x < 0 ? -x : x)
# define MIN(a, b) (a < b ? a : b)
# define MAX(a ,b) (a > b ? a : b)

typedef struct s_point
{
	int	x;
	int	y;
}			t_point;

typedef struct s_map
{
	char	emptychar;
	char	obstchar;
	char	fullchar;
	int		nblines;
	int		nbcolumns;
	int		nbobst;
	t_point	*obstacles;
}			t_map;

void	ft_set_point_value(t_point *pt, int x, int y);

void	ft_swap(t_point *pt1, t_point *pt2);

void	ft_putchar(char c, int exit);

void	ft_putstr(char *str, int exit);

t_map	ft_readFile(char *filename);

int		ft_strlen(char *str);

int		ft_is_printable(char c);

int		ft_strcmp(char *str1, char *str2);

int		ft_map_args_printable(t_map map);

int		ft_is_number(char c);

int		ft_solve(t_map obstacles);

t_map	ft_read_standard(void);

t_map	ft_get_lines_standard(t_map map, int size, int i, int sizeFirstLine);

t_map	ft_get_char_standard(t_map map, char *filemap, int sizeOfFirstLine);

t_map	ft_get_nbobst_standard(t_map map, char *filemap, int i, int nbcolumns);

t_map	ft_get_obstpoints_standard(t_map map, char *filemap, int i, int j);

t_map	ft_map_error(t_map map, int ismalloced);

t_map	ft_map_error_standard(t_map map, int ismalloced, char *filemap);

char	*ft_reader(void);

int		ft_is_mapchar(char c, t_map map);
#endif
