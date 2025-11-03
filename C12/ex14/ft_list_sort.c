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

void    ft_list_sort(t_list **begin_list, int (*cmp)())
{
    int     swapped;
    t_list  *ptr;
    void    *temp;

    if (!begin_list || !*begin_list)
        return ;
    swapped = 1;
    while (swapped)
    {
        swapped = 0;
        ptr = *begin_list;
        while (ptr->next)
        {
            if ((*cmp)(ptr->data, ptr->next->data) > 0)
            {
                temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
    }
}