/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:03:11 by dsindres          #+#    #+#             */
/*   Updated: 2024/07/10 15:18:50 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_algo(t_list **a, t_list **b, int len)
{
	int	len_a;

	while (len > 3)
	{
		pb(b, a);
		len--;
	}
	algo_for_3(a);
	while (*b)
	{
		init_big_algo(*a, *b);
		exec_algo(a, b);
	}
	len_a = li_size(*a);
	if (in_order(a) == 1)
		put_in_order(a, len_a);
	return ;
}

void	init_big_algo(t_list *a, t_list *b)
{
	int	len_b;
	int	len_a;

	len_b = li_size(b);
	len_a = li_size(a);
	init_big_algo_0(a);
	init_big_algo_0(b);
	quid_mediane(a);
	quid_mediane(b);
	position(a);
	position(b);
	target(a, b);
	price(b, len_a, len_b);
}

void	init_big_algo_0(t_list *li)
{
	while (li)
	{
		li->price = 0;
		li->mediane = 0;
		li->position = 0;
		li->target = NULL;
		li = li->next;
	}
}

void	exec_algo(t_list **a, t_list **b)
{
	t_list	*cheap;

	cheap = find_cheapest(b);
	if (cheap->target->mediane == 0)
	{
		if (cheap->mediane == 0)
			big_algo_1(a, b, cheap);
		else
			big_algo_2(a, b, cheap);
	}
	else
	{
		if (cheap->mediane == 0)
			big_algo_3(a, b, cheap);
		else
			big_algo_4(a, b, cheap);
	}
}

void	position(t_list *a)
{
	int		i;

	i = 1;
	while (a)
	{
		a->position = i;
		a = a->next;
		i++;
	}
}
