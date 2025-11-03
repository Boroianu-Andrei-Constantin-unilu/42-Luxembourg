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

void    ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
    t_list  *new;
    t_list  *current;
    t_list  *previous;

    if (!begin_list)
        return ;
    new = ft_create_elem(data);
    if (!new)
        return ;
    if (!begin_list || (*cmp)(data, (*begin_list)->data) < 0)
    {
        new->list = *begin_list;
        *begin_list = new;
        return ;
    }
    previous = *begin_list;
    current = previous->next;
    while (current && (*cmp)(current->data, data) < 0)
    {
        previous = current;
        current = current->next;
    }
    previous->next = new;
    new->next = current;
}