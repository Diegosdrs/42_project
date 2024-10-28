/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:15:00 by dsindres          #+#    #+#             */
/*   Updated: 2024/07/23 10:57:32 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	second_command(char **av, int *fd, char **envp)
{
	int	file;

	file = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file == -1)
		ft_error();
	if (dup2(fd[0], STDIN_FILENO) == -1)
		ft_error();
	if (dup2(file, STDOUT_FILENO) == -1)
		ft_error();
	close(fd[1]);
	close(file);
	do_command(av[3], envp);
}

void	first_command(char **av, int *fd, char **envp)
{
	int	file;

	file = open(av[1], O_RDONLY, 0777);
	if (file == -1)
		ft_error();
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		ft_error();
	if (dup2(file, STDIN_FILENO) == -1)
		ft_error();
	close(fd[0]);
	close(file);
	do_command(av[2], envp);
}

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid;
	pid_t	pid_2;

	if (ac != 5)
		return (ft_putstr_fd("Error : Wrong number of arguments\n", 2), -1);
	if (check_command(av) == 1)
		return (-1);
	if (pipe(fd) == -1)
		ft_error();
	pid = fork();
	if (pid == -1)
		ft_error();
	if (pid == 0)
		first_command(av, fd, envp);
	pid_2 = fork();
	if (pid_2 == -1)
		ft_error();
	if (pid_2 == 0)
		second_command(av, fd, envp);
	close(fd[1]);
	close(fd[0]);
	waitpid(pid, NULL, 0);
	waitpid(pid_2, NULL, 0);
	return (0);
}
