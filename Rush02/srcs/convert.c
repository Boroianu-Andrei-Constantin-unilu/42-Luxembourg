/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboroia <anboroia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:03:52 by jrivero-          #+#    #+#             */
/*   Updated: 2025/11/02 21:19:40 by anboroia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

static void	print_digit(int digit, t_dict *d, int *first)
{
	char	buf[2];

	buf[0] = digit + '0';
	buf[1] = '\0';
	if (!*first)
		ft_putspace();
	ft_putstr(find_value(d, buf));
	*first = 0;
}

static void	print_tens(int t, int u, t_dict *d, int *first)
{
	char	buf[4];

	if (t == 1)
	{
		buf[0] = '1';
		buf[1] = u + '0';
		buf[2] = '\0';
		if (!*first)
			ft_putspace();
		ft_putstr(find_value(d, buf));
		*first = 0;
		return ;
	}
	if (t > 1)
	{
		buf[0] = t + '0';
		buf[1] = '0';
		buf[2] = '\0';
		if (!*first)
			ft_putspace();
		ft_putstr(find_value(d, buf));
		*first = 0;
	}
	if (u && t != 1)
		print_digit(u, d, first);
}

static void	print_hundreds(int n, t_dict *d, int *first)
{
	int		h;
	int		t;
	int		u;

	h = n / 100;
	t = (n % 100) / 10;
	u = n % 10;
	if (h)
	{
		print_digit(h, d, first);
		ft_putspace();
		ft_putstr(find_value(d, "100"));
		*first = 0;
	}
	print_tens(t, u, d, first);
}

static void	print_group(int n, char *scale, t_dict *d, int *first)
{
	if (n == 0)
		return ;
	print_hundreds(n, d, first);
	if (scale)
	{
		ft_putspace();
		ft_putstr(find_value(d, scale));
		*first = 0;
	}
}

void	print_number(char *number, t_dict *dict)
{
	long	nb;
	int		g[4];
	int		first;

	nb = 0;
	first = 1;
	while (*number)
		nb = nb * 10 + (*number++ - '0');
	if (nb == 0)
	{
		ft_putstr(find_value(dict, "0"));
		ft_putstr("\n");
		return ;
	}
	g[0] = nb / 1000000000;
	g[1] = (nb / 1000000) % 1000;
	g[2] = (nb / 1000) % 1000;
	g[3] = nb % 1000;
	print_group(g[0], "1000000000", dict, &first);
	print_group(g[1], "1000000", dict, &first);
	print_group(g[2], "1000", dict, &first);
	print_group(g[3], NULL, dict, &first);
	ft_putstr("\n");
}
