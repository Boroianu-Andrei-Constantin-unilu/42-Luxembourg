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

void    ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
    t_list  *last;

    if (!begin_list1)
        return ;
    if (!*begin_list1)
    {
        *begin_list1 = begin_list2;
        return ;
    }
    last = *begin_list1;
    while (last->next)
        last = last->next;
    last->next = begin_list2;
}