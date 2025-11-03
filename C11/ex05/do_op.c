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

int	ft_atoi(char *str);
int	add(int a, int b);
int	sub(int a, int b);
int	mul(int a, int b);
int	divi(int a, int b);
int	mod(int a, int b);

void	ft_putnbr(int nb)
{
	char	c;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	c = nb % 10 + '0';
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	int	(*ops[5])(int, int);
	char	*s;
	int	a;
	int	b;

	if (ac != 4)
		return (0);
	ops[0] = add;
	ops[1] = sub;
	ops[2] = mul;
	ops[3] = divi;
	ops[4] = mod;
	a = ft_atoi(av[1]);
	b = ft_atoi(av[3]);
	s = av[2];
	if (s[1] != '\0')
		return (write(1, "0\n", 2), 0);
	if (*s == '/' && b == 0)
		return (write(1, "Stop : division by zero\n", 24), 0);
	if (*s == '%' && b == 0)
		return (write(1, "Stop : modulo by zero\n", 22), 0);
	if (*s == '+')
		ft_putnbr(ops[0](a, b));
	else if (*s == '-')
		ft_putnbr(ops[1](a, b));
	else if (*s == '*')
		ft_putnbr(ops[2](a, b));
	else if (*s == '/')
		ft_putnbr(ops[3](a, b));
	else if (*s == '%')
		ft_putnbr(ops[4](a, b));
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}
