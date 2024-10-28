/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:13:43 by artberna          #+#    #+#             */
/*   Updated: 2024/10/25 17:11:34 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_cmd(t_cmds **head, t_cmds **curr, t_gdata *data)
{
	*head = ft_calloc(sizeof(t_cmds), 1);
	*curr = *head;
	ft_memset(*curr, 0, sizeof(t_cmds));
	(*curr)->cmd = NULL;
	(*curr)->next = NULL;
	(*curr)->prev = NULL;
	(*curr)->redir = NULL;
	(*curr)->g_data = data;
	data->nb_command = 1;
}

t_cmds	*parser(t_token *tok, t_gdata *data)
{
	t_cmds	*head;
	t_cmds	*curr;
	t_token	*tmp;

	head = NULL;
	curr = NULL;
	tmp = tok;
	init_cmd(&head, &curr, data);
	handle_dollar(tmp, data);
	parsenize(curr, tmp, data);
	// print_token(tmp); // debug
	return (head);
}
