/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboroia <anboroia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:03:52 by jrivero-          #+#    #+#             */
/*   Updated: 2025/11/02 19:25:53 by anboroia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define DICT_PATH "numbers.dict"
# define BUF_SIZE 4096

typedef struct s_dict
{
	char	*key;
	char	*value;
}	t_dict;

int		rush02(char *dict_path, char *number);
t_dict	*load_dict(char *path);
void	free_dict(t_dict *dict);
char	*find_value(t_dict *dict, char *key);
int		parse_number(char *str);
void	print_number(char *number, t_dict *dict);
int		ft_strlen(char *s);
char	*ft_strdup(char *s);
int		ft_strcmp(char *a, char *b);
void	ft_putstr(char *s);
void	ft_putspace(void);
char	*ft_strndup(char *s, int n);
char	*ft_strjoin(char *a, char *b, char sep);
void	print_error(char *msg);

#endif
