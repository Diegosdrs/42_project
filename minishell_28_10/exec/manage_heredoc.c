/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:14:21 by dsindres          #+#    #+#             */
/*   Updated: 2024/10/28 09:43:09 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	manage_hdoc(t_cmds *cmds)
{
	t_cmds	*temp;
	int		i;
	pid_t	pid;
	int		status;

	temp = cmds;
	i = 0;
	pid = fork();
	if (pid == -1)
		return ;
	if (pid == 0)
	{
		while (temp != NULL)
		{
			if (is_it_heredoc(temp) == 1)
				create_hdoc_file(temp, create_file_name(i));
			temp = temp->next;
			i++;
		}
		exit(EXIT_SUCCESS);
	}
	waitpid(pid, &status, 0);
	cmds->g_data->heredoc = get_exit_code(status);
	affect_heredoc_name(cmds);
	init_signal(0, cmds->g_data);
}

const char	*create_file_name(int i)
{
	char		*str;
	const char	*str_2;

	str = ft_itoa(i);
	str_2 = ft_strjoin_no_free("/tmp/HDOC_FILE", str);
	free(str);
	return (str_2);
}

void	create_hdoc_file(t_cmds *cmds, const char *str)
{
	int		fd;
	char	*line;
	t_token	*temp_tok;

	init_signal(1, cmds->g_data);
	line = NULL;
	temp_tok = cmds->redir;
	while (temp_tok != NULL)
	{
		if (temp_tok->type == TOK_HDOC)
		{
			fd = open(str, O_CREAT | O_TRUNC | O_WRONLY, 0644);
			if (fd < 0)
				ft_error("Failed to open HDOC_FILE", cmds);
			while (1)
			{
				if (input_heredoc(temp_tok, line, fd) == 0
					|| cmds->g_data->heredoc == 1)
					break ;
			}
			close (fd);
		}
		temp_tok = temp_tok->next;
	}
}

int	input_heredoc(t_token *temp_tok, char *line, int fd)
{
	line = readline("> ");
	if (line == NULL || ft_strncmp(line, temp_tok->token,
			(ft_strlen(line) + ft_strlen(temp_tok->token))) == 0)
	{
		if (line == NULL)
			ft_putstr_fd("minishell: warning: heredoc: called end-of-line\n", 2);
		free(line);
		return (0);
	}
	ft_putstr_fd(line, fd);
	ft_putstr_fd("\n", fd);
	free(line);
	return (1);
}
