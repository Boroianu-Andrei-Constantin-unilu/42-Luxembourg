/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboroia <anboroia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:12:12 by yourlogin         #+#    #+#             */
/*   Updated: 2025/11/05 17:31:41 by anboroia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*read_file(char *filename);
t_map	*parse_map(char *content);
int		validate_map(t_map *map);
t_square	find_biggest_square(t_map *map);
void	fill_square(t_map *map, t_square sq);
void	display_map(t_map *map);
void	print_error(void);
void	free_map(t_map *map);
int		ft_strlen(char *s);
int		ft_min(int a, int b);

#endif
