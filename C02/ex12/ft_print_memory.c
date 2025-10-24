/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboroia <anboroia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:45:05 by anboroia          #+#    #+#             */
/*   Updated: 2025/10/23 22:46:16 by anboroia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_hex(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	ft_putchar(hex[c / 16]);
	ft_putchar(hex[c % 16]);
}

void	ft_print_address(unsigned long addr)
{
	char	str[16];
	int		i;

	i = 16;
	while (i--)
	{
		str[i] = "0123456789abcdef"[addr % 16];
		addr /= 16;
	}
	write(1, str, 16);
}

void	ft_print_content(unsigned char *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < 16)
	{
		if (i < size)
			ft_print_hex(addr[i]);
		else
			write(1, "  ", 2);
		if (i % 2)
			write(1, " ", 1);
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (addr[i] >= 32 && addr[i] <= 126)
			ft_putchar(addr[i]);
		else
			ft_putchar('.');
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*p;

	p = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		ft_print_address((unsigned long)(p + i));
		write(1, ": ", 2);
		if (size - i < 16)
			ft_print_content(p + i, size - i);
		else
			ft_print_content(p + i, 16);
		write(1, "\n", 1);
		i += 16;
	}
	return (addr);
}
