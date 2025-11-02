/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboroia <anboroia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:03:52 by jrivero-          #+#    #+#             */
/*   Updated: 2025/11/02 21:19:30 by anboroia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*dup;

	i = 0;
	if (!s)
		return (NULL);
	dup = malloc(ft_strlen(s) + 1);
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strndup(char *s, int n)
{
	char	*p;
	int		i;

	i = 0;
	p = malloc(n + 1);
	if (!p)
		return (NULL);
	while (i < n && s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

int	ft_strcmp(char *a, char *b)
{
	while (*a && *b && *a == *b)
	{
		a++;
		b++;
	}
	return ((unsigned char)*a - (unsigned char)*b);
}

void	ft_putstr(char *s)
{
	if (s)
		write(1, s, ft_strlen(s));
}
