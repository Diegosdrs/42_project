/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:45:11 by dsindres          #+#    #+#             */
/*   Updated: 2024/10/25 17:15:29 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	my_cd(t_env *struct_env, t_cmds *t_cmds)
{
	DIR		*path;

	if (t_cmds->cmd[1] != NULL)
		path = opendir(t_cmds->cmd[1]);
	if (t_cmds->cmd[1] == NULL
		|| ft_strncmp(t_cmds->cmd[1], "~", 10) == 0)
		cd_dir_env(struct_env, "HOME");
	else if (ft_strncmp(t_cmds->cmd[1], ".", 10) == 0
		|| ft_strncmp(t_cmds->cmd[1], "./", 10) == 0)
		return ;
	else if (ft_strncmp(t_cmds->cmd[1], "-", 10) == 0)
		cd_dir_env(struct_env, "OLDPWD");
	else
		my_cd_2(struct_env, t_cmds, path);
}

void	my_cd_2(t_env *struct_env, t_cmds *t_cmds, DIR *path)
{
	if (ft_strncmp(t_cmds->cmd[1], "..", 10) == 0
		|| ft_strncmp(t_cmds->cmd[1], "../", 10) == 0)
		cd_dir_move_up(struct_env, "..");
	else if (path != NULL)
		cd_dir_path(struct_env, t_cmds->cmd[1]);
	else
	{
		if (t_cmds->cmd[1] != NULL)
			closedir(path);
		ft_error("cd fonctions ", t_cmds);
		return ;
	}
	if (t_cmds->cmd[1] != NULL)
		closedir(path);
}

void	cd_dir_path(t_env *struct_env, char *path)
{
	char	*actual_dir;
	char	*old_dir;

	old_dir = getcwd(NULL, 0);
	chdir(path);
	actual_dir = getcwd(NULL, 0);
	replace_dir(struct_env, "PWD", actual_dir, old_dir);
	free(actual_dir);
	free(old_dir);
}

void	cd_dir_move_up(t_env *struct_env, char *dir)
{
	char	*new_dir;
	char	*new_actual_dir;
	char	*actual_dir;

	new_dir = display_dir(dir, NULL);
	if (!new_dir)
		return ;
	actual_dir = getcwd(NULL, 0);
	chdir(new_dir);
	new_actual_dir = getcwd(NULL, 0);
	replace_dir(struct_env, "PWD", new_actual_dir, actual_dir);
	free(actual_dir);
	free(new_dir);
	free(new_actual_dir);
}

void	cd_dir_env(t_env *struct_env, char *dir)
{
	char	*actual_dir;
	char	*old_dir;
	char	*new_dir;

	actual_dir = getcwd(NULL, 0);
	if (ft_strncmp(dir, "HOME", 10) == 0)
		chdir(getenv("HOME"));
	else
	{
		old_dir = ft_getenv(struct_env, dir, NULL);
		if (old_dir == NULL)
		{
			old_dir = ft_strdup(struct_env->oldpwd);
			chdir(old_dir);
			free(old_dir);
		}
		else
			chdir(old_dir);
	}
	new_dir = getcwd(NULL, 0);
	replace_dir(struct_env, "PWD", new_dir, actual_dir);
	free(actual_dir);
	free(new_dir);
}
