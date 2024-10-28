/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:12:01 by dsindres          #+#    #+#             */
/*   Updated: 2024/07/09 16:05:36 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list **li)
{
	t_list	*last;

	if (!li || !(*li) || !((*li)->next))
		return ;
	last = last_li(*li);
	last->prev->next = NULL;
	last->next = *li;
	last->prev = NULL;
	*li = last;
	last->next->prev = last;
}

void	rra(t_list **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_list **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
