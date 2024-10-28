/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_heredoc_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:55:42 by dsindres          #+#    #+#             */
/*   Updated: 2024/10/24 16:56:56 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	affect_heredoc_name(t_cmds *cmds)
{
	t_cmds	*temp;
	char	*str_i;
	int		i;
	char	*str_total;

	i = 0;
	temp = cmds;
	while (temp != NULL)
	{
		if (is_it_heredoc(temp) == 1)
		{
			str_i = ft_itoa(i);
			str_total = ft_strjoin_no_free("/tmp/HDOC_FILE", str_i);
			free(str_i);
			temp->hdoc = ft_strdup(str_total);
			free(str_total);
			i++;
		}
		temp = temp->next;
	}
}

void	supp_all_hdoc_file(t_cmds *cmds)
{
	t_cmds	*temp;

	temp = cmds;
	while (temp != NULL)
	{
		if (is_it_heredoc(temp) == 1)
		{
			unlink(temp->hdoc);
			free((void *)temp->hdoc);
		}
		temp = temp->next;
	}
}
