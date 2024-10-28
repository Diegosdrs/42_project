/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:37:25 by artberna          #+#    #+#             */
/*   Updated: 2024/06/18 10:30:00 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_library.h"

int	ft_putchar_printf(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_printf(char *str, int fd)
{
	int	count;

	count = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*str != '\0')
	{
		count += ft_putchar_printf(*str, fd);
		str++;
	}
	return (count);
}

int	ft_putnbr_printf(int n, int fd)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		count += ft_putchar_printf('-', fd);
		n = -n;
	}
	if (n >= 10)
	{
		count += ft_putnbr_printf(n / 10, fd);
		n = n % 10;
	}
	count += ft_putchar_printf(n + 48, fd);
	return (count);
}

int	ft_putnbrun_printf(unsigned int n, int fd)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count += ft_putnbrun_printf(n / 10, fd);
		n = n % 10;
	}
	count += ft_putchar_printf(n + 48, fd);
	return (count);
}

int	ft_putnbrbase_printf(unsigned long n, int fd, char c, int interupt)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (c == 'p' && n == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	if (c == 'p' && interupt == 0)
	{
		count += ft_putchar_printf('0', STDOUT_FILENO);
		count += ft_putchar_printf('x', STDOUT_FILENO);
	}
	if (c == 'X')
		base = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_putnbrbase_printf(n / 16, fd, c, 1);
	count += ft_putchar_printf(base[n % 16], fd);
	return (count);
}
