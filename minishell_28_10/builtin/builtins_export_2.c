/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_export_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:24:46 by dsindres          #+#    #+#             */
/*   Updated: 2024/10/24 10:26:46 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	my_export_create(t_env *struct_env, t_cmds *t_cmds, int len)
{
	int		i;
	int		j;
	char	**tab_var;

	i = 0;
	j = 0;
	tab_var = ft_calloc(len + 2, sizeof(char *));
	if (!tab_var)
		return ;
	while (struct_env->tab_env[i])
	{
		tab_var[i] = ft_strdup(struct_env->tab_env[i]);
		if (!tab_var[i])
		{
			free_double_tab(tab_var, i);
			return ;
		}
		i++;
	}
	my_export_create_2(struct_env, t_cmds, tab_var, i);
	return ;
}

void	my_export_create_2(t_env *struct_env, t_cmds *t_cmds,
		char **tab_var, int index)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	tab_var[index] = ft_calloc((ft_strlen(t_cmds->cmd[1]) + 1), sizeof(char));
	while (t_cmds->cmd[1][i])
	{
		tab_var[index][i] = t_cmds->cmd[1][i];
		i++;
	}
	tab_var[index + 1] = NULL;
	free_double_tab(struct_env->tab_env, -1);
	struct_env->len++;
	struct_env->tab_env = tab_var;
	return ;
}

void	my_export_replace(t_env *struct_env, t_cmds *t_cmds, int index)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (index == -1)
		return ;
	free(struct_env->tab_env[index]);
	struct_env->tab_env[index] = NULL;
	struct_env->tab_env[index]
		= ft_calloc(ft_strlen(t_cmds->cmd[1]) + 1, sizeof(char));
	while (t_cmds->cmd[1][i])
	{
		struct_env->tab_env[index][i] = t_cmds->cmd[1][i];
		i++;
	}
	struct_env->tab_env[index][i] = '\0';
	return ;
}

void	my_export_replace2(t_env *struct_env, t_cmds *t_cmds, int index)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (index == -1)
		return ;
	free(struct_env->tab_env[index]);
	struct_env->tab_env[index] = NULL;
	struct_env->tab_env[index] = ft_calloc(ft_strlen(t_cmds->cmd[1])
			+ ft_strlen(t_cmds->cmd[2]) + 2, sizeof(char));
	while (t_cmds->cmd[1][i])
	{
		struct_env->tab_env[index][i] = t_cmds->cmd[1][i];
		i++;
	}
	struct_env->tab_env[index][i] = '=';
	i++;
	while (t_cmds->cmd[2][j])
	{
		struct_env->tab_env[index][i] = t_cmds->cmd[2][j];
		i++;
		j++;
	}
	struct_env->tab_env[index][i] = '\0';
}
