/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_unset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:09:08 by dsindres          #+#    #+#             */
/*   Updated: 2024/10/23 11:56:10 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	my_unset(t_env *struct_env, t_cmds *t_cmds)
{
	int	i;

	if (ft_strncmp(t_cmds->cmd[1], "OLDPWD", 10) == 0)
	{
		if (ft_getenv(struct_env, "OLDPWD") != NULL)
			struct_env->oldpwd = ft_strdup(ft_getenv(struct_env, "OLDPWD"));
	}
	i = is_new_var_env(struct_env, t_cmds);
	if (i != -1)
	{
		if (valide_value_env(struct_env->tab_env, t_cmds->cmd, i) == 0)
			my_unset_delete(struct_env, i);
	}
}

int	valide_value_env(char **env, char **cmd, int index)
{
	int	i;

	i = 0;
	if (cmd[2] == NULL)
		return (0);
	while (env[index][i] != '=')
		i++;
	i++;
	if (ft_strncmp(cmd[2], i + env[index],
			ft_strlen(cmd[2]) + ft_strlen(env[index])) == 0
		&& cmd[3] == NULL)
		return (0);
	return (1);
}

void	my_unset_delete(t_env *struct_env, int index)
{
	int		i;
	int		j;
	char	**new_env;

	new_env = ft_calloc(struct_env->len, sizeof(char *));
	if (!new_env)
		return ;
	i = 0;
	j = 0;
	while (i < struct_env->len - 1)
	{
		if (i == index)
			j++;
		new_env[i] = ft_strdup(struct_env->tab_env[j]);
		if (!new_env[i])
			return (free_double_tab(new_env, i));
		i++;
		j++;
	}
	new_env[i] = NULL;
	struct_env->len--;
	free_double_tab(struct_env->tab_env, -1);
	struct_env->tab_env = new_env;
	return ;
}
