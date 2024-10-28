/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_fonctions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:39:46 by dsindres          #+#    #+#             */
/*   Updated: 2024/10/28 09:40:18 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtins_fonctions(t_cmds *cmd, t_env *struct_env)
{
	if ((ft_strncmp(cmd->cmd[0], "env", 10) == 0) && cmd->cmd[1] == NULL)
		my_env(struct_env);
	else if (ft_strncmp(cmd->cmd[0], "pwd", 10) == 0)
		my_pwd();
	else if (ft_strncmp(cmd->cmd[0], "export", 10) == 0)
		my_export(struct_env, cmd);
	else if (ft_strncmp(cmd->cmd[0], "unset", 10) == 0
		&& cmd->cmd[1] != NULL)
		my_unset(struct_env, cmd);
	else if (ft_strncmp(cmd->cmd[0], "echo", 10) == 0)
		my_echo(cmd->cmd);
	else if (ft_strncmp(cmd->cmd[0], "cd", 10) == 0)
		my_cd(struct_env, cmd);
	else if (ft_strncmp(cmd->cmd[0], "exit", 10) == 0)
	{
		my_exit(struct_env, cmd);
		cmd->g_data->heredoc = g_sig_code;
	}
	else
		return (ft_error("builtins fonctions", cmd), 1);
	return (0);
}

void	my_env(t_env *struct_env)
{
	int		i;

	i = 0;
	while (struct_env->tab_env[i])
	{
		putstr(struct_env->tab_env[i]);
		write(1, "\n", 1);
		i++;
	}
	return ;
}

void	my_pwd(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		return ;
	putstr(pwd);
	write(1, "\n", 1);
	free (pwd);
	return ;
}

void	my_echo(char **cmd)
{
	int	i;

	if (cmd[1] == NULL)
		write(1, "\n", 1);
	else if (ft_strncmp(cmd[1], "-n", 4) == 0)
	{
		i = 2;
		while (cmd[i])
		{
			putstr(cmd[i]);
			if (cmd[i + 1] != NULL)
				write(1, " ", 1);
			i++;
		}
	}
	else if (ft_strncmp(cmd[1], "-n", 4) != 0)
		my_echo_2(cmd);
}

void	my_echo_2(char **cmd)
{
	int	i;

	i = 1;
	while (cmd[i])
	{
		putstr(cmd[i]);
		write(1, " ", 1);
		if (cmd[i + 1] == NULL)
			write(1, "\n", 1);
		i++;
	}
}
