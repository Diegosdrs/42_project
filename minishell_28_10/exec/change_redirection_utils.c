/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_redirection_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:43:31 by dsindres          #+#    #+#             */
/*   Updated: 2024/10/18 11:29:02 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*last_token_node(t_cmds *cmds, int flag)
{
	t_token	*temp;

	if (cmds->nb_redir == 0)
		return (NULL);
	temp = cmds->redir;
	while (temp->next)
		temp = temp->next;
	while (temp)
	{
		if (flag == 0)
		{
			if (temp->type == TOK_OR
				|| temp->type == TOK_APP)
				return (temp);
		}
		else
		{
			if (temp->type == TOK_IR
				|| temp->type == TOK_HDOC)
				return (temp);
		}
		temp = temp->prev;
	}
	return (NULL);
}

int	create_file(t_cmds *cmds)
{
	t_token	*temp;

	temp = cmds->redir;
	while (temp != NULL)
	{
		if (create_file_2(temp) == 1)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	create_file_2(t_token *temp)
{
	int	fd;

	if (temp->type == TOK_APP)
		fd = open(temp->token, O_CREAT | O_APPEND, 0777);
	else if (temp->type == TOK_OR)
		fd = open(temp->token, O_CREAT | O_TRUNC, 0777);
	else
		return (0);
	if (fd < 0)
		return (1);
	close (fd);
	return (0);
}

int	verif_file(t_cmds *cmds)
{
	t_token	*temp;

	temp = cmds->redir;
	while (temp != NULL)
	{
		if (temp->type == TOK_IR)
		{
			if (verif_file_2(temp->token) == 1)
				return (1);
		}
		temp = temp->next;
	}
	return (0);
}

int	verif_file_2(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY, 0777);
	if (fd < 0)
		return (1);
	close (fd);
	return (0);
}
