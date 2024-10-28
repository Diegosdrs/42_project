/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:38:50 by artberna          #+#    #+#             */
/*   Updated: 2024/10/15 17:40:05 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_close_quote(char *s, char c)
{
	int	i;

	i = 1;
	while (s[i] && s[i] != c)
		i++;
	return (i + 1);
}

static int	get_token_str_len(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_strrchr(IS_TOKEN, s[i]) || (s[i] == ' ' || s[i] == '\t'))
			break ;
		i++;
	}
	return (i);
}

static int	get_token_len(char *s, t_token_type type)
{
	int	len;

	len = 0;
	if (type == TOK_IR || type == TOK_OR || type == TOK_PIPE || type == TOK_SPC)
		len = 1;
	else if (type == TOK_APP || type == TOK_HDOC)
		len = 2;
	else if (type == TOK_STR)
		len = get_token_str_len(s);
	else if (type == TOK_S_Q)
		len = get_close_quote(s, '\'');
	else if (type == TOK_D_Q)
		len = get_close_quote(s, '\"');
	return (len);
}

static t_token_type	get_token_type(char *s)
{
	if (s[0] == '|')
		return (TOK_PIPE);
	else if (s[0] == '<')
	{
		if (s[1] == '<')
			return (TOK_HDOC);
		return (TOK_IR);
	}
	else if (s[0] == '>')
	{
		if (s[1] == '>')
			return (TOK_APP);
		return (TOK_OR);
	}
	else if (s[0] == '\'')
		return (TOK_S_Q);
	else if (s[0] == '\"')
		return (TOK_D_Q);
	else if (s[0] == ' ')
		return (TOK_SPC);
	return (TOK_STR);
}

t_token	*tokenize(char *s)
{
	int				len;
	t_token			*node;
	t_token_type	type;

	len = 0;
	node = NULL;
	type = get_token_type(s);
	len = get_token_len(s, type);
	node = create_token(s, len, type);
	return (node);
}
