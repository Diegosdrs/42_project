/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:16:30 by artberna          #+#    #+#             */
/*   Updated: 2024/10/25 17:01:36 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_error(char *msg)
{
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(": numeric argument required\n", 2);
}

static int	has_letter(char *str)
{
	int	i;
	int	letter;

	i = 0;
	letter = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
			letter++;
		i++;
	}
	return (letter);
}

int	my_exit(t_env *env, t_cmds *cmd)
{
	int	len;
	int	letter;

	len = 0;
	while (cmd->cmd[len])
		len++;
	letter = 0;
	if (len > 1)
		letter = has_letter(cmd->cmd[1]);
	printf("DANS MY EXIT\n"); // debug
	printf("LEN = %d\n", len); // debug
	printf("LETTER = %d\n", letter); // debug
	ft_putstr_fd("MYexit\n", 2); // enlever MY
	if (len < 3 || letter)
	{
		if (letter)
		{
			print_error(cmd->cmd[1]);
			g_sig_code = 2;
		}
		else if (len == 2)
			g_sig_code = ft_atoi(cmd->cmd[1]);
		printf("SIGCODE ATOI = %d\n", g_sig_code); // debug
		free_double(env->tab_env);
		free_minishell(cmd, cmd->g_data->s_tok, cmd->g_data->input);
		exit(g_sig_code);
	}
	ft_putstr_fd("minishell: exit: too many arguments\n", 2);
	return (g_sig_code = EXIT_FAILURE);
}
