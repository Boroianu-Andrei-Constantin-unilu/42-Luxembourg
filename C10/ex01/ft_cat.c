/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboroia <anboroia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:45:05 by anboroia          #+#    #+#             */
/*   Updated: 2025/10/22 18:47:43 by anboroia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>

#define BUF_SIZE 28672

static void	print_error(const char *prog, const char *file)
{
	const char	*err;
	size_t		lenp;
	size_t		lenf;
	size_t		lene;

	err = strerror(errno);
	lenp = 0;
	lenf = 0;
	lene = 0;
	while (prog && prog[lenp])
		lenp++;
	while (file && file[lenf])
		lenf++;
	while (err && err[lene])
		lene++;
	if (lenp)
	{
		write(2, prog, lenp);
		write(2, ": ", 2);
	}
	if (lenf)
	{
		write(2, file, lenf);
		write(2, ": ", 2);
	}
	if (lene)
		write(2, err, lene);
	write(2, "\n", 1);
}

static void	cat_fd(int fd)
{
	char	buf[BUF_SIZE];
	ssize_t	r;

	r = read(fd, buf, BUF_SIZE);
	while (r > 0)
	{
		if (write(1, buf, (size_t)r) < 0)
			return ;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	fd;

	if (argc == 1)
	{
		cat_fd(0);
		return (0);
	}
	fd = open(argv[i], O_RDONLY);
	while (i < argc)
	{
		if (fd < 0)
			print_error(basename(argv[0]), argv[i]);
		else
		{
			cat_fd(fd);
			close(fd);
		}
		i++;
	}
	return (0);
}
