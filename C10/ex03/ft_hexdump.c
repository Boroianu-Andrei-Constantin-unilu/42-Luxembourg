/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboroia <anboroia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:45:05 by anboroia          #+#    #+#             */
/*   Updated: 2025/10/22 20:37:25 by anboroia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>
#include <ctype.h>

static void	print_error(const char *prog, const char *file)
{
	const char	*err;

	if (prog && *prog)
	{
		write(2, prog, strlen(prog));
		write(2, ": ", 2);
	}
	if (file && *file)
	{
		write(2, file, strlen(file));
		write(2, ": ", 2);
	}
	err = strerror(errno);
	if (err && *err)
		write(2, err, strlen(err));
	write(2, "\n", 1);
}

static void	print_offset(unsigned int off)
{
	char		buf[9];
	const char	*hex;
	int			i;

	buf[8] = 0;
	hex = "0123456789abcdef";
	i = 7;
	while (i >= 0)
	{
		buf[i] = hex[off & 0xF];
		off >>= 4;
		i--;
	}
	write(1, buf, 8);
	write(1, "  ", 2);
}

static void	print_hex_line(unsigned char *b, ssize_t n)
{
	const char	*hex;
	char		hh[3];
	for (int i = 0; i < 16; i++)
	{
		if (i < n)
		{
			hex = "0123456789abcdef";
			hh[0] = hex[(b[i] >> 4) & 0xF];
			hh[1] = hex[b[i] & 0xF];
			hh[2] = 0;
			write(1, hh, 2);
		}
		else
			write(1, "  ", 2);
		if (i % 2)
			write(1, " ", 1);
	}
}

static void	print_ascii(unsigned char *b, ssize_t n)
{
	char	c;

	write(1, " |", 2);
	for (int i = 0; i < n; i++)
	{
		c = (isprint(b[i]) ? (char)b[i] : '.');
		write(1, &c, 1);
	}
	write(1, "|\n", 2);
}

static void	process_fd(int fd, const char *name)
{
	unsigned char	buf[16];
	ssize_t			r;
	unsigned int	offset = 0;

	r = read(fd, buf, 16);
	while (r > 0)
	{
		print_offset(offset);
		print_hex_line(buf, r);
		print_ascii(buf, r);
		offset += (unsigned int)r;
	}

	if (r < 0)
		print_error("hexdump", name ? name : "stdin");
}

int	main(int argc, char **argv)
{
	int			i;
	int			fd;
	const char	*prog = basename(argv[0]);

	if (argc == 1)
	{
		process_fd(0, NULL);
		return (0);
	}

	if (argc >= 2 && strcmp(argv[1], "-C") == 0)
		i = 2;
	i = 1;
	if (i >= argc)
	{
		process_fd(0, NULL);
		return 0;
	}

	prog = basename(argv[0]);
	for (; i < argc; i++)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd < 0)
		{
			print_error(prog, argv[i]);
			continue ;
		}
		process_fd(fd, argv[i]);
		close(fd);
	}
	return (0);
}
