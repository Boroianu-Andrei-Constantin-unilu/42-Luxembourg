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

void    ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)())
{
    t_list dummy;
    t_list *tail;
    t_list *a;
    t_list *b;

    if (!begin_list1)
        return ;
    a = *begin_list1;
    b = begin_list2;
    dummy.next = NULL;
    tail = &dummy;
    while (a && b)
    {
        if ((*cmp)(a->data, b->data) <= 0)
        {
            tail->next = a;
            a = a->next;
        }
        else
        {
            tail->next = b;
            b = b->next;
        }
    tail = tail->next;
    }
    if (a)
        tail->next = a;
    else
        tail->next = b;
    *begin_list1 = dummy.next;
}