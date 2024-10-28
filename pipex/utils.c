/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:41:18 by dsindres          #+#    #+#             */
/*   Updated: 2024/07/22 15:41:18 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return ;
}

char	*find_command(char *command, char **envp)
{
	int		i;
	char	**long_path_split;
	char	*path_split;
	char	*final_path;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH", 4) == NULL)
		i++;
	long_path_split = ft_split(envp[i] + 5, ':');
	i = 0;
	while (long_path_split[i])
	{
		path_split = ft_strjoin(long_path_split[i], "/");
		final_path = ft_strjoin(path_split, command);
		free(path_split);
		if (access(final_path, F_OK) == 0)
		{
			ft_free(long_path_split);
			return (final_path);
		}
		free(final_path);
		i++;
	}
	ft_free(long_path_split);
	return (NULL);
}	

void	do_command(char *cmd, char **envp)
{
	int		i;
	char	**command;

	i = 0;
	command = ft_split(cmd, ' ');
	if (access(command[0], F_OK) == 0)
	{
		if (execve(command[0], command, envp) == -1)
		{
			ft_free(command);
			ft_error();
		}
	}
	else
		do_command_2(command, envp);
}

void	do_command_2(char **command, char **envp)
{
	char	*path;

	path = find_command(command[0], envp);
	if (!path)
	{
		ft_free(command);
		ft_error();
	}
	if (execve(path, command, envp) == -1)
	{
		free(path);
		ft_free(command);
		ft_error();
	}
}
