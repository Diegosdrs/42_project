/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:01:22 by artberna          #+#    #+#             */
/*   Updated: 2024/06/18 09:56:52 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_library.h"

static void	ft_putchar_fdstr(char c, int fd)
{
	write(fd, &c, 1);
	return ;
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fdstr(s[i], fd);
		i++;
	}
	return ;
}

/*
int	main(void)
{
	char	*str;

	str = "CHACAAAAAAAAAAAL";
	ft_putstr_fd(str, 1);
	return (0);
}
*/
