/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboroia <anboroia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:03:52 by jrivero-          #+#    #+#             */
/*   Updated: 2025/11/02 21:19:21 by anboroia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

void	print_error(char *msg)
{
	ft_putstr(msg);
}

int	rush02(char *dict_path, char *number)
{
	t_dict	*dict;

	if (parse_number(number) == -1)
	{
		print_error("Error\n");
		return (-1);
	}
	dict = load_dict(dict_path);
	if (!dict)
	{
		print_error("Dict Error\n");
		return (-1);
	}
	print_number(number, dict);
	free_dict(dict);
	return (0);
}
