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

void    ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
    t_list  *tmp;
    t_list  *ptr;

    ptr = begin_list;
    while (ptr)
    {
        tmp = ptr->next;
        if (free_fct)
            free_fct(ptr->data);
        free(ptr);
        ptr = tmp;
    }
}