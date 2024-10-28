/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:20:36 by dsindres          #+#    #+#             */
/*   Updated: 2024/07/11 14:15:32 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checkdouble(int value, t_list *li)
{
	while (li != NULL)
	{
		if (value == li->content)
			return (1);
		li = li->next;
	}
	return (0);
}

void	free_lst(t_list *li)
{
	t_list	*temp;

	while (li != NULL)
	{
		temp = li;
		li = li->next;
		free(temp);
	}
}

int	create_list(char **str, t_list **li)
{
	int		i;
	long	value;

	i = 0;
	while (str[i])
	{
		value = ft_atolong(str[i]);
		if (checkdouble(value, *li) == 0
			&& value >= INT_MIN && value <= INT_MAX)
			init_list(value, li);
		else
			return (1);
		i++;
	}
	return (0);
}

void	init_list(int value, t_list **li)
{
	t_list	*element;
	t_list	*temp;

	element = ft_calloc(sizeof(*element), 1);
	if (!element)
		return ;
	element->content = value;
	element->next = NULL;
	element->prev = NULL;
	if (*li == NULL)
	{
		*li = element;
		return ;
	}
	else
	{
		temp = *li;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = element;
		element->prev = temp;
	}
}

/* void	print_list(t_list **li)
{
	t_list	*current;

	current = *li;
	while (current)
	{
		ft_printf("|     %d\n", current->content);
		current = current->next;
	}
} */
