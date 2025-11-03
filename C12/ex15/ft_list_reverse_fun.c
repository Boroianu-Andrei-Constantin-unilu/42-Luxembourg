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

void    ft_list_reverse_fun(t_list *begin_list)
{
    int len;
    t_list *ptr;
    t_list *a;
    t_list *b;
    int i;
    int j;
    void *tmp;

    len = 0;
    ptr = begin_list;
    while (ptr)
    {
        len++;
        ptr = ptr->next;
    }
    i = 0;
    while (i < len / 2)
    {
        a = begin_list;
        b = begin_list;
        j = 0;
        while (j < i)
        {
            a = a->next;
            j++;
        }
    j = 0;
    while (j < len - 1 - i)
    {
        b = b->next;
        j++;
    }
    tmp = a->data;
    a->data = b->data;
    b->data = tmp;
    i++;
    }
}