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

int ft_is_sort(int *tab, int length, int (*f)(int, int))
{
    int i;
    int dir;

    if (length < 2)
        return (1);
    i = 0;
    while (i < length - 1 && f(tab[i], tab[i + 1]) == 0)
        i++;
    if (i == length - 1)
        return (1);
    dir = f(tab[i], tab[i + 1]);
    while (i < length - 1)
    {
        if ((dir < 0 && f(tab[i], tab[i + 1]) > 0) || (dir > 0 && f(tab[i], tab[i + 1]) < 0))
            return (0);
        i++;
    }
    return (1);
}