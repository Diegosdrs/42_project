/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_for_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:10:42 by dsindres          #+#    #+#             */
/*   Updated: 2024/07/11 14:27:40 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_for_5(t_list **a, t_list **b, int len)
{
	t_list	*min;

	min = *a;
	while (len > 3)
	{
		min = find_min(*a);
		push_min(a, b, min);
		len--;
	}
	algo_for_3(a);
	pa(a, b);
	pa(a, b);
}

void	push_min(t_list **a, t_list **b, t_list *min)
{
	t_list	*temp;
	int		i;
	int		len;

	len = li_size(*a);
	temp = *a;
	i = 0;
	while (temp != NULL && temp != min)
	{
		temp = temp->next;
		i++;
	}
	if (i < (len / 2))
		moove_ra(a, b, i);
	else
		moove_rra(a, b, i, len);
}

t_list	*find_min(t_list *a)
{
	long			smallest;
	t_list			*smallest_node;

	if (NULL == a)
		return (NULL);
	smallest = LONG_MAX;
	while (a)
	{
		if (a->content < smallest)
		{
			smallest = a->content;
			smallest_node = a;
		}
		a = a->next;
	}
	return (smallest_node);
}

void	moove_rra(t_list **a, t_list **b, int i, int len)
{
	int	count;

	count = len - i;
	while (count > 0)
	{
		rra(a);
		count--;
	}
	pb(b, a);
	return ;
}

void	moove_ra(t_list **a, t_list **b, int i)
{
	int	count;

	count = i;
	while (count > 0)
	{
		ra(a);
		count--;
	}
	pb(b, a);
	return ;
}
