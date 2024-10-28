/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:55:05 by artberna          #+#    #+#             */
/*   Updated: 2024/10/25 17:30:20 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_sig_code = 0;

static void	handle_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_sig_code = SIGINT + SIGOFFSET;
	printf ("SIGCODE = %d \n", g_sig_code);
}

static void	handle_sigint_child(int sig)
{
	static int	i;

	(void)sig;
	i = 0;
	write(STDOUT_FILENO, "\n", 1);
	signal(SIGINT, SIG_IGN);
	if (i >= 1)
		write(STDOUT_FILENO, "\n", 1);
	i++;
	g_sig_code = SIGINT + SIGOFFSET;
	printf ("CHILD SIGCODE = %d \n", g_sig_code);
}

static void	handle_sigquit_child(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "Quit (core dumped)\n", 19);
	g_sig_code = SIGQUIT + SIGOFFSET;
	printf ("CHILD SIGCODE = %d \n", g_sig_code);
}

static void	init_sigint_heredoc(int sig, t_gdata *data)
{
	(void)sig;
	data->heredoc = 1;
	printf("heredoc dans sig = %d\n", data->heredoc);
	write(STDOUT_FILENO, "^C\n", 3);
	rl_replace_line("", 0);
	rl_redisplay();
	g_sig_code = SIGINT + SIGOFFSET;
	printf ("HDOC SIGCODE = %d \n", g_sig_code);
	exit(EXIT_SUCCESS);
}

void	init_signal(int option, t_gdata *data)
{
	if (option == 0)
	{
		printf("NORMAL MODE\n"); //debug
		data->heredoc = 0;
		signal(SIGINT, handle_sigint);
		signal(SIGQUIT, SIG_IGN);
	}
	if (option == 1)
	{
		printf("HDOC MODE\n"); //debug
		signal(SIGINT, (void (*)(int))init_sigint_heredoc);
		signal(SIGQUIT, SIG_IGN);
	}
	if (option == 2)
	{
		printf("CHILD MODE\n"); //debug
		signal(SIGQUIT, handle_sigquit_child);
		signal(SIGINT, handle_sigint_child);
	}
}
