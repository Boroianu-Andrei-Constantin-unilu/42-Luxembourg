/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboroia <anboroia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:03:52 by jrivero-          #+#    #+#             */
/*   Updated: 2025/11/02 21:19:16 by anboroia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

static int	count_lines(char *buf)
{
	int	i;
	int	lines;

	i = 0;
	lines = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			lines++;
		i++;
	}
	return (lines + 1);
}

static char	*skip_space(char *s)
{
	while (*s == ' ' || *s == '\t')
		s++;
	return (s);
}

static void	parse_line(t_dict *dict, char **line, int *i)
{
	char	*colon;
	char	*end;
	char	*key_start;
	char	*value_start;

	colon = *line;
	while (*colon && *colon != ':')
		colon++;
	if (!*colon)
		return ;
	end = colon;
	while (*end && *end != '\n')
		end++;
	key_start = skip_space(*line);
	value_start = skip_space(colon + 1);
	dict[*i].key = ft_strndup(key_start, colon - key_start);
	dict[*i].value = ft_strndup(value_start, end - value_start);
	(*i)++;
	if (*end)
		*line = end + 1;
	else
		*line = end;
}

static t_dict	*parse_buffer(char *buf)
{
	int		i;
	int		lcount;
	char	*line;
	t_dict	*dict;

	lcount = count_lines(buf);
	dict = malloc(sizeof(t_dict) * (lcount + 1));
	if (!dict)
		return (NULL);
	line = buf;
	i = 0;
	while (*line)
	{
		parse_line(dict, &line, &i);
		if (i > 0 && !dict[i - 1].key)
			break ;
	}
	dict[i].key = NULL;
	dict[i].value = NULL;
	return (dict);
}

t_dict	*load_dict(char *path)
{
	int		fd;
	ssize_t	bytes;
	char	*buf;
	t_dict	*dict;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	buf = malloc(BUF_SIZE + 1);
	if (!buf)
		return (NULL);
	bytes = read(fd, buf, BUF_SIZE);
	close(fd);
	if (bytes <= 0)
	{
		free(buf);
		return (NULL);
	}
	buf[bytes] = '\0';
	dict = parse_buffer(buf);
	free(buf);
	return (dict);
}
