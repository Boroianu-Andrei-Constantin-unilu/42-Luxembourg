/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboroia <anboroia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:45:05 by anboroia          #+#    #+#             */
/*   Updated: 2025/10/22 18:44:13 by anboroia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 4096

static void	ft_putstr_fd(const char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	if (i)
		write(fd, s, i);
}

int	main(int argc, char **argv)
{
	int		fd;
	ssize_t	ret;
	char	buf[BUF_SIZE];

	if (argc == 1)
	{
		ft_putstr_fd("File name missing.\n", 2);
		return (1);
	}
	if (argc > 2)
	{
		ft_putstr_fd("Too many arguments.\n", 2);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Cannot read file.\n", 2);
		return (1);
	}
	ret = read(fd, buf, BUF_SIZE);
	while (ret > 0)
	{
		if (write(1, buf, (size_t)ret) < 0)
		{
			close(fd);
			ft_putstr_fd("Cannot read file.\n", 2);
			return (1);
		}
	}
	close(fd);
	return (0);
}
