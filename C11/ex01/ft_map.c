/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboroia <anboroia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:45:05 by anboroia          #+#    #+#             */
/*   Updated: 2025/10/22 18:44:13 by anboroia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int    *ft_map(int *tab, int length, int (*f)(int))
{
    int	*res;
    int	i;

    res = (int *)malloc(sizeof(int) * length);
    if (!res)
        return (0);
    i = 0;
    while (i < length)
    {
        res[i] = f(tab[i]);
        i++;
    }
    return (res);
}