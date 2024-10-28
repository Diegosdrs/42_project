/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:29:54 by dsindres          #+#    #+#             */
/*   Updated: 2024/10/25 15:00:41 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell_exec(t_cmds *cmds, t_gdata *data)
{
	pid_t	*pid;

	if (is_it_heredoc_2(cmds) == 1)
		manage_hdoc(cmds);
	if (is_it_builtins(cmds) == 0 && cmds->g_data->nb_command == 1
		&& is_it_heredoc(cmds) == 0)
		redirection(cmds, &data->s_env);
	else if (cmds->g_data->nb_command == 1)
		one_command(cmds, &data->s_env);
	else
	{
		init_signal(2, cmds->g_data);
		pid = init_pid(cmds);
		multiple_commands(cmds, &data->s_env, pid);
		all_waitpid(cmds, pid);
		free (pid);
	}
	if (is_it_heredoc_2(cmds) == 1)
		supp_all_hdoc_file(cmds);
}

void	multiple_commands(t_cmds *cmds, t_env *struct_env, pid_t *pid)
{
	int		fd[2];
	int		infile;
	t_cmds	*temp;
	int		i;

	i = 0;
	infile = STDIN_FILENO;
	temp = cmds;
	while (temp != NULL)
	{
		if (pipe(fd) == -1 && temp->next != NULL)
			return (ft_error("pipe failed ", temp));
		pid[i] = fork();
		if (pid[i] == -1)
			return (fork_error(temp, fd));
		temp->flag_error = 1;
		if (pid[i] == 0)
			child_process(temp, infile, fd, struct_env);
		else
			parent_process(fd, &infile);
		temp = temp->next;
		i++;
	}
	if (infile != STDIN_FILENO)
		close(infile);
}

void	parent_process(int *fd, int *infile)
{
	close(fd[1]);
	if (*infile != STDIN_FILENO)
		close(*infile);
	*infile = fd[0];
}

void	child_process(t_cmds *temp, int infile, int *fd, t_env *struct_env)
{
	if (infile != STDIN_FILENO)
	{
		dup2(infile, STDIN_FILENO);
		close(infile);
	}
	if (temp->next != NULL)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
	}
	close(fd[0]);
	redirection(temp, struct_env);
	exit(0);
}
