/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboroia <anboroia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:03:52 by jrivero-          #+#    #+#             */
/*   Updated: 2025/11/02 21:19:27 by anboroia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

int	parse_number(char *str)
{
	int	i;

	if (!str || !*str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}
