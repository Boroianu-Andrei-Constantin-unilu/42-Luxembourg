/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboroia <anboroia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:03:52 by jrivero-          #+#    #+#             */
/*   Updated: 2025/11/02 21:19:23 by anboroia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

int	main(int argc, char **argv)
{
	char	*dict_path;
	char	*number;

	if (argc == 2)
	{
		dict_path = DICT_PATH;
		number = argv[1];
	}
	else if (argc == 3)
	{
		dict_path = argv[1];
		number = argv[2];
	}
	else
	{
		print_error("Error\n");
		return (1);
	}
	if (rush02(dict_path, number) == -1)
		return (1);
	return (0);
}
