/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:05:28 by artberna          #+#    #+#             */
/*   Updated: 2024/06/18 09:56:38 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_library.h"

static void	ft_putchar_fdend(char c, int fd)
{
	write(fd, &c, 1);
	return ;
}

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fdend(s[i], fd);
		i++;
	}
	ft_putchar_fdend('\n', fd);
	return ;
}
/*
int	main(void)
{
	char	*str;

	str = "CHACAAAAAAAAAAAL";
	ft_putendl_fd(str, 1);
	return (0);
}
*/
