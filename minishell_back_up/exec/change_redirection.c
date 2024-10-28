/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:16:03 by dsindres          #+#    #+#             */
/*   Updated: 2024/10/23 13:01:08 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	change_in_stdout(t_cmds *cmds)
{
	int		file_fd;
	t_token	*out;

	out = last_token_node(cmds, 0);
	if (out == NULL || create_file(cmds) == 1)
		return (1);
	if (out->type == TOK_OR)
		file_fd = open(out->token, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (out->type == TOK_APP)
		file_fd = open(out->token, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else
		return (1);
	if (file_fd < 0)
		return (1);
	if (saved_stdout(cmds, file_fd) == 1)
		return (1);
	if (dup2(file_fd, STDOUT_FILENO) < 0)
	{
		close(file_fd);
		return (1);
	}
	close(file_fd);
	return (0);
}

int	saved_stdout(t_cmds *cmds, int file_fd)
{
	cmds->saved_stdout = dup(STDOUT_FILENO);
	if (cmds->saved_stdout < 0)
	{
		close(file_fd);
		return (1);
	}
	return (0);
}

int	change_out_stdout(t_cmds *cmds)
{
	if (dup2(cmds->saved_stdout, STDOUT_FILENO) < 0)
	{
		close(cmds->saved_stdout);
		return (1);
	}
	close(cmds->saved_stdout);
	cmds->saved_stdout = 0;
	return (0);
}

int	change_in_stdin(t_cmds *cmds)
{
	int		file_fd;
	t_token	*in;

	if (verif_file(cmds) == 1)
	{
		ft_error("file verif", cmds);
		return (1);
	}
	in = last_token_node(cmds, 1);
	if (in == NULL)
		return (1);
	file_fd_value(in, &file_fd, cmds);
	if (file_fd < 0)
		return (1);
	cmds->saved_stdin = dup(STDIN_FILENO);
	if (cmds->saved_stdin < 0
		|| dup2(file_fd, STDIN_FILENO) < 0)
	{
		close(file_fd);
		return (1);
	}
	close(file_fd);
	return (0);
}

int	change_out_stdin(t_cmds *cmds)
{
	if (dup2(cmds->saved_stdin, STDIN_FILENO) < 0)
	{
		close(cmds->saved_stdin);
		return (1);
	}
	close(cmds->saved_stdin);
	cmds->saved_stdin = 0;
	return (0);
}
