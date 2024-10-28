/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:09:51 by artberna          #+#    #+#             */
/*   Updated: 2024/06/18 09:56:48 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_library.h"

static void	ft_putchar_fdnbr(char c, int fd)
{
	write(fd, &c, 1);
	return ;
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fdnbr('-', fd);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		n = n % 10;
	}
	ft_putchar_fdnbr(n + 48, fd);
	return ;
}

/*
int	main(void)
{
	int	i;

	i = 2147483647;
	ft_putnbr_fd(i, 1);
	return (0);
}
*/