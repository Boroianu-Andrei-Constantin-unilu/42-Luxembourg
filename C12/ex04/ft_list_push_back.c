/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboroia <anboroia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:45:05 by anboroia          #+#    #+#             */
/*   Updated: 2025/10/23 14:42:17 by anboroia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_list.h"

void    ft_list_push_back(t_list **begin_list, void *data)
{
    t_list  *new;
    t_list  *last;

    if (!begin_list)
        return ;
    new = ft_create_elem(data);
    if (!new)
        return ;
    if (!*begin_list)
    {
        *begin_list = new;
        return ;
    }
    last = *begin_list;
    while (last->next)
        last = last->next;
    last->next = new;
}