/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:29:56 by dsindres          #+#    #+#             */
/*   Updated: 2024/07/23 10:25:21 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_command(char **av)
{
	if (ft_strlen(av[2]) == 0 && ft_strlen(av[3]) == 0)
	{
		ft_putstr_fd("Error : permission denied\nError : permission denied\n", 2);
		return (1);
	}
	if (ft_strlen(av[3]) == 0 && av[2][0] != ' ')
		ft_putstr_fd("Error : permission denied\n", 2);
	if (ft_strlen(av[2]) == 0 && av[3][0] != ' ')
		ft_putstr_fd("Error : permission denied\n", 2);
	return (check_command_2(av));
}

int	check_command_2(char **av)
{
	if (av[2][0] == ' ' && av[3][0] == ' ')
	{
		ft_putstr_fd("Error : command not found\nError : command not found\n", 2);
		return (1);
	}
	if (av[2][0] == ' ' && ft_strlen(av[3]) == 0)
	{
		ft_putstr_fd("Error : command not found\nError : permission denied\n", 2);
		return (1);
	}
	if (av[3][0] == ' ' && ft_strlen(av[2]) == 0)
	{
		ft_putstr_fd("Error : permission denied\nError : command not found\n", 2);
		return (1);
	}
	if (av[2][0] == ' ')
		ft_putstr_fd("Error : command not found\n", 2);
	if (av[3][0] == ' ')
	{
		ft_putstr_fd("Error : command not found\n", 2);
		return (1);
	}
	return (0);
}
