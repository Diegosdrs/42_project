/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:43:36 by dsindres          #+#    #+#             */
/*   Updated: 2024/08/07 10:09:42 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_double(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	print_double(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		ft_printf("%s\n", str[i]);
		i++;
	}
}

void	error_fd(void)
{
	ft_printf("Erreur : lecture impossible\n");
	exit(EXIT_FAILURE);
}

void	error_fd_2(int fd)
{
	close(fd);
	error_fd();
}

void	error_fd_3(char **map, int i)
{
	while (i-- > 0)
		free(map[i]);
	free(map);
	exit(EXIT_FAILURE);
}
