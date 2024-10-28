/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:45:47 by dsindres          #+#    #+#             */
/*   Updated: 2024/10/24 15:00:54 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	my_export(t_env *struct_env, t_cmds *t_cmds)
{
	int	i;
	int	j;

	j = 0;
	if (t_cmds->cmd[1] == NULL)
	{
		export_sort(struct_env);
		return ;
	}
	i = is_new_var_env_2(struct_env, t_cmds, j);
	if (i != -1)
		my_export_replace(struct_env, t_cmds, i);
	else
	{
		if (good_input(t_cmds) == 0)
			my_export_create(struct_env, t_cmds, struct_env->len);
		else
		{
			if (ft_isalpha(t_cmds->cmd[1][0]) == 0)
				my_error(t_cmds->cmd[1], " : not a valid identifier\n", t_cmds);
		}
	}
}

int	good_input(t_cmds *cmds)
{
	char	*str;
	int		i;
	int		egal_count;
	int		letter_count;

	i = 0;
	str = cmds->cmd[1];
	egal_count = 0;
	letter_count = 0;
	if (str[0] == '=' || ft_isalpha(str[0]) == 0)
		return (1);
	while (str[i])
	{
		if (ft_isalnum(str[i]) == 0 && str[i] != '_' && str[i] != '=')
			return (1);
		if (str[i] == '=')
			egal_count++;
		if (ft_isalpha(str[i]) == 1)
			letter_count++;
		i++;
	}
	if (egal_count == 0 || letter_count == 0)
		return (1);
	return (0);
}

int	is_new_var_env_2(t_env *struct_env, t_cmds *t_cmds, int j)
{
	int		i;
	char	*new_path;

	i = 0;
	while (struct_env->tab_env[i])
	{
		j = 0;
		while (struct_env->tab_env[i][j] != '=')
			j++;
		j++;
		new_path = ft_calloc(j + 1, sizeof(char));
		j = 0;
		while (struct_env->tab_env[i][j] != '=')
		{
			new_path[j] = struct_env->tab_env[i][j];
			j++;
		}
		new_path[j] = struct_env->tab_env[i][j];
		if (ft_strncmp(new_path, t_cmds->cmd[1],
				(ft_strlen(new_path) + ft_strlen(t_cmds->cmd[1]))) == 0)
			return (free(new_path), i);
		free(new_path);
		i++;
	}
	return (-1);
}

int	is_new_var_env(t_env *struct_env, t_cmds *t_cmds)
{
	int		i;
	int		j;
	char	*new_path;

	i = 0;
	while (struct_env->tab_env[i])
	{
		j = 0;
		while (struct_env->tab_env[i][j] != '=')
			j++;
		new_path = ft_calloc(j + 1, sizeof(char));
		j = 0;
		while (struct_env->tab_env[i][j] != '=')
		{
			new_path[j] = struct_env->tab_env[i][j];
			j++;
		}
		if (ft_strncmp(new_path, t_cmds->cmd[1],
				(ft_strlen(new_path) + ft_strlen(t_cmds->cmd[1]))) == 0)
			return (free(new_path), i);
		free(new_path);
		i++;
	}
	return (-1);
}
