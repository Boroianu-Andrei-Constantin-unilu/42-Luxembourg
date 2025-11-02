/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboroia <anboroia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:03:52 by jrivero-          #+#    #+#             */
/*   Updated: 2025/11/02 21:19:19 by anboroia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

void	free_dict(t_dict *dict)
{
	int	i;

	i = 0;
	if (!dict)
		return ;
	while (dict[i].key)
	{
		free(dict[i].key);
		free(dict[i].value);
		i++;
	}
	free(dict);
}

char	*find_value(t_dict *dict, char *key)
{
	int	i;

	i = 0;
	if (!dict || !key)
		return (NULL);
	while (dict[i].key)
	{
		if (ft_strcmp(dict[i].key, key) == 0)
			return (dict[i].value);
		i++;
	}
	return (NULL);
}
