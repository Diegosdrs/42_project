/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:49:32 by dsindres          #+#    #+#             */
/*   Updated: 2024/10/24 15:03:52 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error(char *str, t_cmds *cmds)
{
	if (errno == ENOENT)
		perror(str);
	if (cmds->flag_error == 1)
		exit (EXIT_FAILURE);
}

void	putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	free_double_tab(char **tab, int i)
{
	if (i == -1)
	{
		i = 0;
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free (tab);
		return ;
	}
	else
	{
		while (i >= 0)
		{
			free (tab[i]);
			i--;
		}
		free (tab);
		return ;
	}
}

int	init_struct_env(char **env, t_env *struct_env)
{
	int	i;

	i = 0;
	if (env == NULL)
		return (1);
	struct_env->tab_env = NULL;
	while (env[i])
		i++;
	struct_env->len = i;
	struct_env->oldpwd = NULL;
	struct_env->tab_env = copy_tab(env, i);
	return (0);
}

char	**copy_tab(char **tab_to_copy, int len)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_calloc(len + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	while (i < len)
	{
		tab[i] = ft_strdup(tab_to_copy[i]);
		i++;
	}
	return (tab);
}
