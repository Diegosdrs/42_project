/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:09:27 by artberna          #+#    #+#             */
/*   Updated: 2024/10/18 15:40:59 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	str_error(t_token *tok)
{
	if (is_cmd(tok->type))
	{
		if (tok->token[0] == '!' && tok->token[1] == '\0')
			return (1);
		if (tok->token[0] == ':' && tok->token[1] == '\0')
			return (1);
		if (tok->token[0] == '#')
			return (1);
	}
	return (0);
}

static int	redir_error(t_token *tok)
{
	if (is_redir(tok->type))
	{
		if (tok->type == TOK_IR && !tok->next)
			return (printf("%s", NL_ERROR), 1);
		else if (tok->type == TOK_IR && (tok->next->type == TOK_OR || \
		(tok->next->type == TOK_SPC && tok->next->next->type == TOK_OR)))
			return (printf("%s", OR_ERROR), 1);
		else if (!tok->next || (tok->type == TOK_OR && \
		(tok->next->type == TOK_IR || (tok->type == TOK_SPC && \
			tok->next->next->type == TOK_IR))))
			return (printf("%s", NL_ERROR), 1);
		else if (tok->type == TOK_IR && ((tok->next->type == TOK_IR) \
		|| (tok->next->type == TOK_SPC && tok->next->next->type == TOK_IR)))
			return (printf("%s", IR_ERROR), 1);
		else if (tok->type == TOK_OR && ((tok->next->type == TOK_OR) \
		|| (tok->next->type == TOK_SPC && tok->next->next->type == TOK_OR)))
			return (printf("%s", OR_ERROR), 1);
		else if (tok->type == TOK_APP && ((tok->next->type == TOK_APP) \
		|| (tok->next->type == TOK_SPC && tok->next->next->type == TOK_APP)))
			return (printf("%s", APP_ERROR), 1);
		else if (tok->type == TOK_HDOC && ((tok->next->type == TOK_HDOC) \
		|| (tok->next->type == TOK_SPC && tok->next->next->type == TOK_HDOC)))
			return (printf("%s", HDOC_ERROR), 1);
	}
	return (0);
}

static int	pipe_error(t_token *tok)
{
	if (tok->type == TOK_PIPE)
	{
		if (!tok->prev || !tok->next)
			return (ft_printf("%s", PIPE_ERROR), 1);
		if (!is_cmd(tok->prev->type) && tok->prev->type != TOK_SPC)
			return (ft_printf("%s", PIPE_ERROR), 1);
		if (!is_cmd(tok->next->type) && tok->next->type != TOK_SPC)
			return (ft_printf("%s", PIPE_ERROR), 1);
		if (tok->next->type == TOK_SPC)
		{
			if (!tok->next->next)
				return (ft_printf("%s", PIPE_ERROR), 1);
		}
		if (tok->prev->type == TOK_SPC)
		{
			if (!tok->prev->prev || !is_cmd(tok->prev->prev->type))
				return (ft_printf("%s", PIPE_ERROR), 1);
		}
	}
	return (0);
}

int	error_handler(t_token **tok, t_gdata *data)
{
	int		error;
	t_token	*tmp;

	error = 0;
	tmp = *tok;
	while (tmp)
	{
		error += pipe_error(tmp);
		error += redir_error(tmp);
		error += str_error(tmp);
		if (error)
			return (free_minishell(NULL, *tok, data->input), error);
		if ((tmp)->next)
			(tmp) = (tmp)->next;
		else
			return (error);
	}
	return (error);
}
