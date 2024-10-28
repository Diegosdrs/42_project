/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_exit_code.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:12:25 by artberna          #+#    #+#             */
/*   Updated: 2024/10/25 17:48:24 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_exit_code(int status)
{
	int	to_ret;

	to_ret = 0;
	if (WIFEXITED(status))
	{
		g_sig_code = 0;
		return (WEXITSTATUS(status));
	}
	else if (WIFSIGNALED(status))
	{
		to_ret = g_sig_code;
		return (to_ret);
	}
	return (-1);
}
