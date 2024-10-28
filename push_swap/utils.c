/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:50:36 by dsindres          #+#    #+#             */
/*   Updated: 2024/07/10 15:10:59 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	li_size(t_list *li)
{
	int		i;

	i = 0;
	if (li == NULL)
		return (0);
	while (li)
	{
		++i;
		li = li->next;
	}
	return (i);
}

t_list	*last_li(t_list *li)
{
	if (li == NULL)
		return (NULL);
	while (li->next)
		li = li->next;
	return (li);
}

int	in_order(t_list **a)
{
	t_list	*temp;

	temp = *a;
	while (temp->next != NULL)
	{
		if (temp->content > temp->next->content)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	put_in_order(t_list **a, int len)
{
	t_list	*temp;
	int		interupt;
	int		i;

	i = 1;
	temp = *a;
	interupt = 0;
	while (temp->next != NULL && interupt == 0)
	{
		if (temp->content > temp->next->content)
			interupt = 1;
		temp = temp->next;
		i++;
	}
	put_in_order2(a, len, i);
}

void	put_in_order2(t_list **a, int len, int i)
{
	int	count;

	if (i <= (len / 2))
	{
		count = i - 1;
		while (count > 0)
		{
			ra(a);
			count--;
		}
	}
	else
	{
		count = len - i + 1;
		while (count > 0)
		{
			rra(a);
			count--;
		}
	}
}
