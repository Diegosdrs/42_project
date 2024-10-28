/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:36:31 by artberna          #+#    #+#             */
/*   Updated: 2024/06/18 09:56:11 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_library.h"

static void	ft_lstclearmap(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*next;

	tmp = *lst;
	if (!lst || !del || !*lst)
		return ;
	while (tmp != NULL)
	{
		next = tmp->next;
		del(tmp->content);
		free(tmp);
		tmp = next;
	}
	*lst = NULL;
}

static t_list	*ft_lstnewmap(void *content)
{
	t_list	*new_elem;

	new_elem = malloc(sizeof(t_list));
	if (!new_elem)
		return (NULL);
	new_elem->content = content;
	new_elem->next = NULL;
	return (new_elem);
}

static void	ft_lstadd_backmap(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!new)
		exit(EXIT_FAILURE);
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new ;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_ls;
	t_list	*new_step;
	void	*param;

	if (!lst || !f || !del)
		return (NULL);
	new_ls = NULL;
	while (lst != NULL)
	{
		param = f(lst->content);
		new_step = ft_lstnewmap(param);
		if (!new_step)
		{
			del(param);
			ft_lstclearmap(&new_ls, del);
			return (NULL);
		}
		ft_lstadd_backmap(&new_ls, new_step);
		lst = lst->next;
	}
	return (new_ls);
}
