/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:17:22 by dsindres          #+#    #+#             */
/*   Updated: 2024/07/10 15:19:41 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_cheapest(t_list **b)
{
	t_list	*cheapest;
	t_list	*temp;

	temp = *b;
	cheapest = *b;
	cheapest->price = temp->price;
	while (temp)
	{
		if (temp->price < cheapest->price)
		{
			cheapest = temp;
			cheapest->price = temp->price;
		}
		temp = temp->next;
	}
	return (cheapest);
}

int	real_position(t_list **li, t_list *pointeur)
{
	int		i;
	t_list	*temp;

	i = 1;
	temp = *li;
	while (temp)
	{
		if (temp == pointeur)
			return (i);
		temp = temp->next;
		i++;
	}
	return (0);
}
