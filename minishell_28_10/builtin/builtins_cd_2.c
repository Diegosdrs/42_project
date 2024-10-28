/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_cd_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:37:23 by dsindres          #+#    #+#             */
/*   Updated: 2024/10/25 17:15:38 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(t_env *struct_env, char *dir, t_gdata *data)
{
	int		index;
	t_cmds	t_dir;
	int		i;

	i = 0;
	if (!ft_strncmp(dir, "?", 1))
	{
		printf ("GETENV EXIT CODE = %d \n", data->exit_code); // exit status
		return (ft_itoa(data->exit_code));
	}
	t_dir.cmd = malloc(sizeof(char *) * (2));
	t_dir.cmd[0] = "cd";
	t_dir.cmd[1] = dir;
	index = is_new_var_env(struct_env, &t_dir);
	if (index == -1)
	{
		free(t_dir.cmd);
		return (NULL);
	}
	while (struct_env->tab_env[index][i] != '=')
		i++;
	i++;
	free(t_dir.cmd);
	return (struct_env->tab_env[index] + i);
}

char	*display_dir(char *cmd, char *old_dir)
{
	DIR				*dir;
	struct dirent	*entry;
	char			*str;

	if (!old_dir)
		dir = opendir(".");
	else
		dir = opendir(old_dir);
	if (dir == NULL)
		return (NULL);
	entry = readdir(dir);
	while (entry != NULL)
	{
		if (ft_strncmp(cmd, entry->d_name, 4) == 0)
		{
			str = ft_strdup(entry->d_name);
			closedir(dir);
			return (str);
		}
		entry = readdir(dir);
	}
	closedir(dir);
	return (NULL);
}

void	replace_dir(t_env *struct_env, char *old_dir,
		char *new_dir, char *new_old_dir)
{
	t_cmds		t_dir;
	int			i;

	i = 0;
	t_dir.cmd = malloc(sizeof(char *) * (4));
	t_dir.cmd[0] = "cd";
	t_dir.cmd[1] = old_dir;
	t_dir.cmd[2] = new_dir;
	t_dir.cmd[3] = NULL;
	i = is_new_var_env(struct_env, &t_dir);
	my_export_replace2(struct_env, &t_dir, i);
	free(t_dir.cmd);
	if (ft_getenv(struct_env, "OLDPWD", NULL) == NULL)
	{
		free(struct_env->oldpwd);
		struct_env->oldpwd = ft_strdup(new_old_dir);
		return ;
	}
	replace_dir_2(struct_env, new_old_dir);
}

void	replace_dir_2(t_env *struct_env, char *new_old_dir)
{
	t_cmds		t_dir;
	int			i;

	i = 0;
	t_dir.cmd = malloc(sizeof(char *) * (4));
	t_dir.cmd[0] = "cd";
	t_dir.cmd[1] = "OLDPWD";
	t_dir.cmd[2] = new_old_dir;
	t_dir.cmd[3] = NULL;
	i = is_new_var_env(struct_env, &t_dir);
	my_export_replace2(struct_env, &t_dir, i);
	free(t_dir.cmd);
}
