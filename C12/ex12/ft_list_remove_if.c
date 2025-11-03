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

void    ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list  *current;
    t_list  *prev;
    t_list  *temp;

    if (!begin_list || !*begin_list)
        return ;
    while (*begin_list && (*cmp)((*begin_list)->data, data_ref) == 0)
    {
        temp = *begin_list;
        if (free_fct)
            (*free_fct)((*begin_list)->data);
        free(*begin_list);
        *begin_list = temp;
    }
    prev = *begin_list;
    if (prev)
        current = prev->next;
    else
        current = NULL;
    while (current)
    {
        if ((*cmp)(current->data, data_ref) == 0)
        {
            prev->next = current->next;
            if (free_fct)
                (*free_fct)(current->data);
            free(current);
            current = prev->next;
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }
}