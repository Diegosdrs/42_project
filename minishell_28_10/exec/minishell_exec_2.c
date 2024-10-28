/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_exec_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:15:00 by dsindres          #+#    #+#             */
/*   Updated: 2024/10/25 17:49:38 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	one_command(t_cmds *cmds, t_env *struct_env)
{
	int		fd[2];
	pid_t	pid;
	int		status;

	init_signal(2, cmds->g_data);
	printf("SGL CMD");
	if (pipe(fd) == -1)
	{
		ft_error("pipe failed ", cmds);
		return ;
	}
	pid = fork();
	if (pid == -1)
	{
		fork_error(cmds, fd);
		return ;
	}
	cmds->flag_error = 1;
	if (pid == 0)
		child_process_one_command(cmds, struct_env);
	close (fd[1]);
	close (fd[0]);
	waitpid(pid, &status, 0);
	cmds->g_data->exit_code = get_exit_code(status);
}

void	child_process_one_command(t_cmds *cmds, t_env *struct_env)
{
	redirection(cmds, struct_env);
	exit(0);
}

void	redirection(t_cmds *cmds, t_env *struct_env)
{
	int	in_flag;
	int	out_flag;

	if (cmds->nb_redir == 0)
		execution(cmds, struct_env);
	else
	{
		in_flag = change_in_stdin(cmds);
		out_flag = change_in_stdout(cmds);
		execution(cmds, struct_env);
		if (in_flag == 0)
			change_out_stdin(cmds);
		if (out_flag == 0)
			change_out_stdout(cmds);
	}
}

pid_t	*init_pid(t_cmds *cmds)
{
	pid_t	*pid;

	pid = ft_calloc(cmds->g_data->nb_command, sizeof(pid_t));
	return (pid);
}

void	all_waitpid(t_cmds *cmds, pid_t *pid)
{
	int	i;
	int	count;
	int	status;

	count = cmds->g_data->nb_command;
	i = 0;
	while (count > 0)
	{
		waitpid(pid[i], &status, 0);
		cmds->g_data->exit_code = get_exit_code(status);
		count--;
		i++;
	}
}
