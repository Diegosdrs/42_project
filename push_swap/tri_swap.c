/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:43:36 by dsindres          #+#    #+#             */
/*   Updated: 2024/07/10 15:11:15 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_s(t_list **li)
{
	int	len;

	len = li_size(*li);
	if (NULL == *li || NULL == li || 1 == len)
		return ;
	*li = (*li)->next;
	(*li)->prev->prev = *li;
	(*li)->prev->next = (*li)->next;
	if ((*li)->next)
		(*li)->next->prev = (*li)->prev;
	(*li)->next = (*li)->prev;
	(*li)->prev = NULL;
}

void	sa(t_list **a)
{
	swap_s(a);
	ft_printf("sa\n");
}

void	sb(t_list **b)
{
	swap_s(b);
	ft_printf("sb\n");
}

void	ss(t_list **a, t_list **b)
{
	swap_s(a);
	swap_s(b);
	ft_printf("ss\n");
}
