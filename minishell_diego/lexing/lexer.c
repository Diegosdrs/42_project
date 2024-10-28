/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:46:15 by artberna          #+#    #+#             */
/*   Updated: 2024/10/08 14:53:12 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handle_quote(char *s)
{
	int	i;
	int	d_quote;
	int	s_quote;

	i = 0;
	d_quote = 0;
	s_quote = 0;
	while (s[i])
	{
		if (s[i] == '\'' && !d_quote)
			s_quote = !s_quote;
		if (s[i] == '\"' && !s_quote)
			d_quote = !d_quote;
		i++;
	}
	if (d_quote % 2 != 0 || s_quote % 2 != 0)
		return (printf("%s", QUOTE_ERROR), 1);
	return (0);
}

static int	add_str_len(char *s, t_token_type type, char *ref)
{
	int	len;

	len = ft_strlen(s);
	if (type == TOK_SPC)
	{
		while (ref[len] == ' ')
			len++;
	}
	else if (type == TOK_S_Q || type == TOK_D_Q)
		len += 2;
	return (len);
}

t_token	*lexer(t_gdata *data)
{
	int		i;
	int		j;
	t_token	*tok;
	t_token	*tmp;

	tok = NULL;
	i = 0;
	j = 0;
	if (handle_quote(data->input))
		return (tok);
	while (data->input[i])
	{
		tmp = tokenize(&data->input[i]);
		if (!tmp)
			return (free_token(tok), free(data->input), NULL);
		tmp->index = j++;
		add_token(&tok, tmp);
		i += add_str_len(tmp->token, tmp->type, &data->input[i]);
	}
	return (tok);
}
