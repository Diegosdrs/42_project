/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_export_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:56:18 by dsindres          #+#    #+#             */
/*   Updated: 2024/10/24 15:02:24 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**export_copy_tab(char **tab_to_copy)
{
	char	**tab;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (tab_to_copy[len])
		len++;
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

void	export_sort(t_env *struct_env)
{
	int		i;
	char	*temp;
	char	*temp_2;
	char	**copy;

	copy = export_copy_tab(struct_env->tab_env);
	i = 0;
	while (copy[i] != NULL && copy[i + 1] != NULL)
	{
		if (ascii_order(copy[i], copy[i + 1]) > 0)
		{
			temp = ft_strdup(copy[i]);
			temp_2 = ft_strdup(copy[i + 1]);
			free (copy[i]);
			free (copy[i + 1]);
			copy[i] = ft_strdup(temp_2);
			copy[i + 1] = ft_strdup(temp);
			free (temp);
			free (temp_2);
			i = -1;
		}
		i++;
	}
	print_var(copy);
	free_double_tab(copy, -1);
}

int	ascii_order(char *str, char *str_2)
{
	int	i;

	i = 0;
	while ((str[i] == str_2[i]) && str[i] != '=' && str_2[i] != '=')
		i++;
	if (str[i] == '=')
		return (str[i - 1] - str_2[i]);
	else if (str_2[i] == '=')
		return (str[i - 1] - str_2[i - 1]);
	else
		return (str[i] - str_2[i]);
}
