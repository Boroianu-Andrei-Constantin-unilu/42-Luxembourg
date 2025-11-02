/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboroia <anboroia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:03:52 by jrivero-          #+#    #+#             */
/*   Updated: 2025/11/02 21:19:32 by anboroia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

void	ft_putspace(void)
{
	write(1, " ", 1);
}

static int	ft_strjoin_len(char *a, char *b, char sep)
{
	int	len;

	len = ft_strlen(a) + ft_strlen(b) + 1;
	if (sep)
		len++;
	return (len);
}

static void	ft_strcpy_at(char *dest, char *src, int *pos)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[*pos] = src[i];
		(*pos)++;
		i++;
	}
}

char	*ft_strjoin(char *a, char *b, char sep)
{
	char	*res;
	int		len;
	int		i;

	if (!a || !b)
		return (NULL);
	len = ft_strjoin_len(a, b, sep);
	res = malloc(len);
	if (!res)
		return (NULL);
	i = 0;
	ft_strcpy_at(res, a, &i);
	if (sep)
		res[i++] = sep;
	ft_strcpy_at(res, b, &i);
	res[i] = '\0';
	return (res);
}
