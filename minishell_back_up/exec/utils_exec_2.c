/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:54:13 by dsindres          #+#    #+#             */
/*   Updated: 2024/10/24 10:46:46 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error(char *str, t_cmds *cmds)
{
	//(void)str;
	if (errno == ENOENT)
		perror(str);
	else
		fprintf(stderr, "%s: command not found\n", cmds->cmd[0]);
	if (cmds->flag_error == 1)
		exit (EXIT_FAILURE);
}

/* void	ft_error(char *command, char *message, t_cmds *cmds)
{
	if (command != NULL)
		write(2, command, ft_strlen(command))
	if (message != NULL)
		write(2, message, ft_strlen(message));
	if (cmds->flag_error == 1)
		exit (EXIT_FAILURE);
} */

void	fork_error(t_cmds *temp, int *fd)
{
	if (temp->next != NULL)
	{
		close(fd[0]);
		close(fd[1]);
	}
	ft_error("fork failed ", temp);
}

int	is_it_heredoc(t_cmds *cmds)
{
	t_token	*temp;

	temp = cmds->redir;
	while (temp != NULL)
	{
		if (temp->type == TOK_HDOC)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	is_it_heredoc_2(t_cmds *cmds)
{
	t_cmds	*temp;
	t_token	*temp_2;

	temp = cmds;
	while (temp != NULL)
	{
		temp_2 = temp->redir;
		while (temp_2 != NULL)
		{
			if (temp_2->type == TOK_HDOC)
				return (1);
			temp_2 = temp_2->next;
		}
		temp = temp->next;
	}
	return (0);
}

void	file_fd_value(t_token *in, int *file_fd, t_cmds *cmds)
{
	if (in->type == TOK_HDOC)
		*file_fd = open(cmds->hdoc, O_RDONLY, 0777);
	else
		*file_fd = open(in->token, O_RDONLY, 0777);
}
