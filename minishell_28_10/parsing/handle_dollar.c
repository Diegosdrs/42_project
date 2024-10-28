/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:06:58 by artberna          #+#    #+#             */
/*   Updated: 2024/10/25 17:16:46 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*copy_str(char *str, char c)
{
	int		len;
	char	*new_str;

	if (!str)
		str = ft_strdup("");
	if (!str)
		return (NULL);
	len = ft_strlen(str);
	new_str = ft_realloc(str, len, len + 2);
	if (!new_str)
		return (free(str), NULL);
	new_str[len] = c;
	new_str[len + 1] = '\0';
	return (new_str);
}

static char	*extract_n_replace(char *s, t_gdata *data, int *i)
{
	int		start;
	char	*to_ret;
	char	*to_find;
	char	*var;

	start = *i + 1;
	(*i)++;
	while (s[*i] && (s[*i] == '_' || ft_isalnum(s[*i]) || s[*i] == '?'))
	{
		if (s[*i] == '$' || s[*i] == '?')
			break ;
		(*i)++;
	}
	if (s[(*i)++] == '?')
		to_find = ft_substr(s, start, 1);
	else
		to_find = ft_substr(s, start, *i - start);
	if (!to_find)
		return (NULL);
	var = ft_getenv(&data->s_env, to_find, data);
	if (var)
		to_ret = ft_strdup(var);
	else
		to_ret = ft_strdup("");
	return (free(var), free(to_find), to_ret);
}

static char	*make_var(char *s, t_gdata *data, int *i, char *result)
{
	char	*tmp;
	char	*new_res;
	int		res_len;

	tmp = extract_n_replace(s, data, i);
	if (!tmp)
		return (free(result), NULL);
	res_len = ft_strlen(result) + ft_strlen(tmp);
	new_res = ft_calloc(res_len + 2, sizeof(char));
	if (!new_res)
		return (free(result), free(tmp), NULL);
	ft_strcpy(new_res, result);
	ft_strcat(new_res, tmp);
	free(result);
	free(tmp);
	return (new_res);
}

static char	*replace_dollar(char *s, t_gdata *data)
{
	int		i;
	char	*result;

	i = 0;
	result = ft_strdup("");
	if (!result)
		return (NULL);
	while (s[i])
	{
		if (s[i] == '$')
		{
			result = make_var(s, data, &i, result);
			if (!result)
				return (NULL);
		}
		else
		{
			result = copy_str(result, s[i++]);
			if (!result)
				return (NULL);
		}
	}
	return (result);
}

void	handle_dollar(t_token *tok, t_gdata *data)
{
	char	*new_token;

	while (tok)
	{
		if ((tok->type == TOK_STR || tok->type == TOK_D_Q) \
		&& !(tok->prev && tok->prev->type == TOK_HDOC) \
		&& !(tok->prev && tok->prev->type == TOK_SPC && \
			tok->prev->prev && tok->prev->prev->type == TOK_HDOC))
		{
			new_token = replace_dollar(tok->token, data);
			if (new_token)
			{
				free(tok->token);
				tok->token = new_token;
			}
		}
		tok = tok->next;
	}
}
