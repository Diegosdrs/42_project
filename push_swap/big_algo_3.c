/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:56:45 by dsindres          #+#    #+#             */
/*   Updated: 2024/07/10 15:29:31 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_algo_1(t_list **a, t_list **b, t_list *cheap)
{
	if (cheap->target->position != 1 && cheap->position != 1)
	{
		while (real_position (b, cheap) > 1
			&& real_position(a, cheap->target) > 1)
			rr(a, b);
	}
	if (real_position(a, cheap->target) == 1 && real_position(b, cheap) != 1)
	{
		while (real_position(b, cheap) > 1)
			rb(b);
	}
	else if (real_position(a, cheap->target) != 1
		&& real_position(b, cheap) == 1)
	{
		while (real_position(a, cheap->target) > 1)
			ra(a);
	}
	else
		pa(a, b);
}

void	big_algo_2(t_list **a, t_list **b, t_list *cheap)
{
	while (real_position(a, cheap->target) > 1)
		ra(a);
	while (real_position(b, cheap) > 1)
		rrb(b);
	pa(a, b);
}

void	big_algo_3(t_list **a, t_list **b, t_list *cheap)
{
	while (real_position(a, cheap->target) > 1)
		rra(a);
	while (real_position(b, cheap) > 1)
		rb(b);
	pa(a, b);
}

void	big_algo_4(t_list **a, t_list **b, t_list *cheap)
{
	int	len_a;
	int	len_b;

	len_a = li_size(*a);
	len_b = li_size(*b);
	while (real_position(b, cheap) > 1 && real_position(a, cheap->target) > 1)
		rrr(a, b);
	if (real_position(a, cheap->target) == 1 && real_position(b, cheap) != 1)
	{
		while (real_position(b, cheap) > 1)
			rrb(b);
	}
	else if (real_position(a, cheap->target) != 1
		&& real_position(b, cheap) == 1)
	{
		while (real_position(a, cheap) > 1)
			rra(a);
	}
	else
		pa(a, b);
}
