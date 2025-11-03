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

t_list  *ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
    t_list  *ptr;

    ptr = begin_list;
    while (ptr)
    {
        if ((*cmp)(ptr->data, data_ref) == 0)
            return (ptr);
        ptr = ptr->next;
    }
    return (NULL);
}