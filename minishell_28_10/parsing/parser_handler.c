/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:14:10 by artberna          #+#    #+#             */
/*   Updated: 2024/10/21 13:44:46 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**create_tab(char *str)
{
	char	**new_tab;

	new_tab = ft_calloc(sizeof(char *), 2);
	if (!new_tab)
		exit_error("Calloc failed");
	new_tab[0] = ft_strdup(str);
	new_tab[1] = NULL;
	return (new_tab);
}

static void	add_to_tab(char *str, t_cmds *cmd)
{
	char	**tmp_tab;
	int		i;
	int		count;

	count = 0;
	if (cmd->cmd)
	{
		while (cmd->cmd[count])
			count++;
		tmp_tab = ft_calloc(sizeof(char *), count + 2);
		if (!tmp_tab)
			exit_error("Calloc failed");
		i = 0;
		while (i < count)
		{
			tmp_tab[i] = cmd->cmd[i];
			i++;
		}
		tmp_tab[i] = ft_strdup(str);
		tmp_tab[i + 1] = NULL;
		free(cmd->cmd);
		cmd->cmd = tmp_tab;
	}
	else
		cmd->cmd = create_tab(str);
}

static char	*copy_str(char *str, t_token **tok)
{
	str = ft_strdup((*tok)->token);
	if (!str)
		return (NULL);
	while ((*tok)->next && is_cmd((*tok)->next->type))
	{
		str = ft_strjoin(str, (*tok)->next->token);
		if (!str)
			return (NULL);
		(*tok) = (*tok)->next;
	}
	return (str);
}

void	parsenize(t_cmds *cmd, t_token *tok, t_gdata *data)
{
	char	*tmp;

	while (tok)
	{
		if (is_cmd(tok->type))
		{
			if (!tok->token || tok->token[0] == '\0')
			{
				tok = tok->next;
				continue ;
			}
			tmp = copy_str(tmp, &tok);
			add_to_tab(tmp, cmd);
			free(tmp);
		}
		else if (tok->type == TOK_PIPE)
			extend_cmd(&cmd, data);
		else if (is_redir(tok->type))
			handle_redir(cmd, &tok);
		tok = tok->next;
	}
}
