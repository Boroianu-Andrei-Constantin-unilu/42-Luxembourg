/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboroia <anboroia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:45:05 by anboroia          #+#    #+#             */
/*   Updated: 2025/10/21 23:12:05 by anboroia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>

static void	print_error(const char *prog, const char *file) {
	const char *err = strerror(errno);

	if (prog && *prog) {
		write(2, prog, strlen(prog));
		write(2, ": ", 2);
	}

	if (file && *file) {
		write(2, file, strlen(file));
		write(2, ": ", 2);
	}

	if (err && *err) {
		write(2, err, strlen(err));
    }

	write(2, "\n", 1);
}

static int	read_all(int fd, char **out, size_t *out_len) {
	size_t cap = 8192;
	size_t len = 0;
	char *buf = (char *)malloc(cap);
	ssize_t r;

	if (!buf) {
		return -1;
    }

	while ((r = read(fd, buf + len, cap - len)) > 0) {
		len += (size_t)r;
		if (cap - len == 0) {
			size_t newcap = cap * 2;
			char *tmp = (char *)realloc(buf, newcap);
			if (!tmp) {
				free(buf);
				return -1;
			}
			buf = tmp;
			cap = newcap;
		}
	}

	if (r < 0) {
		free(buf);
		return -1;
	}

	*out = buf;
	*out_len = len;
	return 0;
}

static void	do_tail(const char *prog, const char *filename, long count) {
	int fd;
	char *data = NULL;
	size_t len = 0;
	size_t start;

	if (filename == NULL) {
		fd = 0;
    } else {
		fd = open(filename, O_RDONLY);
		if (fd < 0) {
			print_error(prog, filename);
			return;
		}
	}

	if (read_all(fd, &data, &len) != 0) {
		if (fd != 0) close(fd);
		print_error(prog, (filename ? filename : "stdin"));
		return;
	}

	if (fd != 0) {
		close(fd);
    }

	if (count < 0) {
        count = 0;
    }

	if ((size_t)count >= len) {
		start = 0;
    } else {
		start = (size_t)len - (size_t)count;
    }

	if (len > 0) {
		write(1, data + start, len - start);
    }

	free(data);
}

int	main(int argc, char **argv) {
	long count = 10;
	int	i = 1;
	const char *prog = basename(argv[0]);

	if (argc >= 2 && strcmp(argv[1], "-c") == 0) {
		if (argc < 3) {
			write(2, "Option requires an argument -- c\n", 33);
			return 1;
		}
		count = atol(argv[2]);
		i = 3;
		if (count < 0) count = 0;
		if (i >= argc) {
			do_tail(prog, NULL, count);
			return 0;
		}
	}

	for (; i < argc; i++) {
		if (argc - ( ( (argc >= 3 && strcmp(argv[1], "-c") == 0) ) ? 3 : 1 ) > 1) {
			write(1, "==> ", 4);
			write(1, argv[i], strlen(argv[i]));
			write(1, " <==\n", 5);
		}
		do_tail(prog, argv[i], count);
		if (i + 1 < argc) {
			write(1, "\n", 1);
        }
	}
	return 0;
}