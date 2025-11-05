/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboroia <anboroia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:45:05 by anboroia          #+#    #+#             */
/*   Updated: 2025/11/05 17:30:14 by anboroia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

static int	init_fd(char *filename)
{
	int	fd;

	if (filename)
		fd = open(filename, O_RDONLY);
	else
		fd = 0;
	return (fd);
}

static char	*append_buffer(char *old, char *buf, ssize_t bytes, size_t len)
{
	char	*tmp;
	size_t	i;

	tmp = malloc(len + bytes + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < len)
	{
		tmp[i] = old[i];
		i++;
	}
	i = 0;
	while (i < (size_t)bytes)
	{
		tmp[len + i] = buf[i];
		i++;
	}
	tmp[len + bytes] = '\0';
	free(old);
	return (tmp);
}

char	*read_file(char *filename)
{
	int		fd;
	char	buf[4096];
	char	*content;
	ssize_t	bytes;
	size_t	len;

	len = 0;
	content = NULL;
	fd = init_fd(filename);
	if (fd < 0)
		return (NULL);
	bytes = read(fd, buf, sizeof(buf));
	while (bytes > 0)
	{
		content = append_buffer(content, buf, bytes, len);
		if (!content)
			break ;
		len += bytes;
		bytes = read(fd, buf, sizeof(buf));
	}
	if (filename)
		close(fd);
	return (content);
}
