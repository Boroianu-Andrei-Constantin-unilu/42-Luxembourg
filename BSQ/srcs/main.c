/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboroia <anboroia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:45:05 by anboroia          #+#    #+#             */
/*   Updated: 2025/11/05 17:25:05 by anboroia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

static void	process_content(char *content)
{
	t_map		*map;
	t_square	sq;

	map = parse_map(content);
	free(content);
	if (!map || !validate_map(map))
	{
		print_error();
		free_map(map);
		return ;
	}
	sq = find_biggest_square(map);
	fill_square(map, sq);
	display_map(map);
	free_map(map);
}

static void	process_file(char *filename)
{
	char	*content;

	content = read_file(filename);
	if (!content)
	{
		print_error();
		return ;
	}
	process_content(content);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
		process_file(NULL);
	else
	{
		while (i < argc)
		{
			process_file(argv[i]);
			if (i < argc - 1)
				write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
