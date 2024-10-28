/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:59:12 by dsindres          #+#    #+#             */
/*   Updated: 2024/09/11 13:59:49 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"

t_list *sort_list(t_list* lst, int (*cmp)(int, int))
{
    int swap;
    t_list *start;

    start = lst;

    while (lst != NULL && lst->next != NULL)
    {
        if ((*cmp)(lst->data, lst->next->data) == 0)
		{
            swap = lst->data;
            lst->data = lst->next->data;
            lst->next->data = swap;
            lst = start;
        }
	else
		lst = lst->next;
    }
    return (start);
}

/* t_list *sort_list(t_list* lst, int (*cmp)(int, int))
{
    int swap;
    t_list *start;

    start = lst;
	if (lst == NULL || lst->next == NULL)
		return (NULL);
    while (lst->next)
    {
        if ((*cmp)(lst->data, lst->next->data) == 0)
	{
            swap = lst->data;
            lst->data = lst->next->data;
            lst->next->data = swap;
            lst = start;
        }
	else
		lst = lst->next;
    }
    return (start);
} */