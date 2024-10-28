/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_for_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:12:49 by dsindres          #+#    #+#             */
/*   Updated: 2024/07/09 11:24:21 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_for_3(t_list **a)
{
	t_list	*max;

	max = find_max(a);
	if (max->content == (*a)->content)
	{
		if ((*a)->next->content > (*a)->next->next->content)
		{
			sa(a);
			rra(a);
		}
		else
			ra(a);
	}
	else if (max->content == (*a)->next->content)
		rra(a);
	if ((*a)->content > (*a)->next->content)
		sa(a);
}

t_list	*find_max(t_list **a)
{
	t_list	*max;
	t_list	*temp;

	temp = *a;
	max = *a;
	while (temp != NULL)
	{
		if (temp->content > max->content)
			max = temp;
		temp = temp->next;
	}
	return (max);
}
