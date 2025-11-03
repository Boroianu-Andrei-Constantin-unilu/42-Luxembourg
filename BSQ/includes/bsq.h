#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_map
{
	int		rows;
	int		cols;
	char	empty;
	char	obstacle;
	char	full;
	char	**grid;
}	t_map;

typedef struct s_square
{
	int		row;
	int		col;
	int		size;
}	t_square;

/* file_utils.c */
char	*read_file(char *filename);

/* parse.c */
t_map	*parse_map(char *content);

/* validate.c */
int		validate_map(t_map *map);

/* solve.c */
t_square	find_biggest_square(t_map *map);
void		fill_square(t_map *map, t_square sq);

/* display.c */
void	display_map(t_map *map);

/* error.c */
void	print_error(void);
void	free_map(t_map *map);

/* utils.c */
int		ft_strlen(char *s);
int		ft_min(int a, int b);

#endif
