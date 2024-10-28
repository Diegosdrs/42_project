/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:52:35 by dsindres          #+#    #+#             */
/*   Updated: 2024/07/10 15:19:09 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	target(t_list *a, t_list *b)
{
	t_list	*temp_a;
	t_list	*target;
	long	best_match_index;

	while (b)
	{
		temp_a = a;
		best_match_index = LONG_MAX;
		while (temp_a)
		{
			if (temp_a->content > b->content
				&& temp_a->content < best_match_index)
			{
				best_match_index = temp_a->content;
				target = temp_a;
			}
			temp_a = temp_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target = find_min(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	quid_mediane(t_list *li)
{
	int		len_li;
	int		i;

	i = 1;
	len_li = li_size(li);
	if (li == NULL)
		return ;
	if (len_li == 1)
	{
		li->mediane = 0;
		return ;
	}
	while (li)
	{
		if (i <= (len_li / 2))
			li->mediane = 0;
		else
			li->mediane = 1;
		i++;
		li = li->next;
	}
}

void	price(t_list *b, int len_a, int len_b)
{
	while (b)
	{
		if (b->target->mediane == 0)
			price_med_0(b, len_b);
		else
			price_med_1(b, len_a, len_b);
		b = b->next;
	}
}

void	price_med_0(t_list *b, int len_b)
{
	if (b->mediane == 0)
	{
		if (b->position > b->target->position)
			b->price = b->position;
		else
			b->price = b->target->position;
	}
	else
		b->price = b->target->position + len_b - b->position;
}

void	price_med_1(t_list *b, int len_a, int len_b)
{
	if (b->mediane == 0)
		b->price = b->position + len_a - b->target->position;
	else
	{
		if (len_b - b->position > len_a - b->target->position)
			b->price = len_b - b->position + 1;
		else
			b->price = len_a - b->target->position + 1;
	}
}
