/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboroia <anboroia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:45:05 by anboroia          #+#    #+#             */
/*   Updated: 2025/10/21 22:17:24 by anboroia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}

int	ft_total_len(int size, char **strs, char *sep)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (i < size)
	{
		total = ft_strlen(strs[i]);
		i++;
	}
	total += (size - 1) * ft_strlen(sep);
	return (total);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total_len;
	char	*result;
	int		i;

	if (size == 0)
	{
		result = malloc(1);
		if (result)
			result[0] = '\0';
		return (result);
	}
	total_len = ft_total_len(size, strs, sep);
	result = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!result)
		return (NULL);
	result[0] = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcat(result, strs[i]);
		if (i < size - 1)
			ft_strcat(result, sep);
		i++;
	}
	return (result);
}
