/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboroia <anboroia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:45:05 by anboroia          #+#    #+#             */
/*   Updated: 2025/10/22 17:38:25 by anboroia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

static char	*ft_strdup(char *src)
{
	int		len;
	char	*dup;
	int		i;

	len = ft_strlen(src);
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static void	free_tab(t_stock_str *tab, int filled)
{
	int	i;

	i = 0;
	while (i < filled)
	{
		if (tab[i].copy)
			free(tab[i].copy);
		i++;
	}
	free(tab);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tab;
	int			i;

	tab = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		tab[i].str = av[i];
		tab[i].copy = ft_strdup(av[i]);
		if (tab[i].copy == NULL)
		{
			free_tab(tab, i);
			return (NULL);
		}
		i++;
	}
	tab[i].str = 0;
	tab[i].copy = 0;
	tab[i].size = 0;
	return (tab);
}
