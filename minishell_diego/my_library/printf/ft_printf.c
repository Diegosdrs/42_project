/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:33:27 by artberna          #+#    #+#             */
/*   Updated: 2024/06/19 17:56:44 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_library.h"

int	ft_write_fmt(const char *fmt, va_list ap)
{
	int	count;

	count = 0;
	if (*fmt == '%')
		count += ft_putchar_printf('%', STDOUT_FILENO);
	else if (*fmt == 'c')
		count += ft_putchar_printf(va_arg(ap, int), STDOUT_FILENO);
	else if (*fmt == 's')
		count += ft_putstr_printf(va_arg(ap, char *), STDOUT_FILENO);
	else if (*fmt == 'd' || *fmt == 'i')
		count += ft_putnbr_printf(va_arg(ap, int), STDOUT_FILENO);
	else if (*fmt == 'u')
		count += ft_putnbrun_printf(va_arg(ap, unsigned int), STDOUT_FILENO);
	else if (*fmt == 'x' || *fmt == 'X')
		count += ft_putnbrbase_printf((unsigned long)va_arg \
		(ap, unsigned int), STDOUT_FILENO, *fmt, 1);
	else if (*fmt == 'p')
		count += ft_putnbrbase_printf((unsigned long)va_arg \
		(ap, void *), STDOUT_FILENO, *fmt, 0);
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	int		count;
	va_list	ap;

	count = 0;
	if (!fmt)
		return (-1);
	if (*fmt == '\0')
		return (0);
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%' && *fmt + 1 == '\0')
			return (-1);
		if (*fmt == '%' && *(++fmt))
			count += ft_write_fmt(fmt, ap);
		else
			count += ft_putchar_printf(*fmt, STDOUT_FILENO);
		++fmt;
	}
	va_end(ap);
	return (count);
}

/*
int	main(void)
{
	int				x;
	int				i;
	char 			c;
	char 			*str;
	unsigned int	usl;

	usl = 100;
	str = NULL;
	c = 'A';
	i = -123456789;
	x = printf("OG printf i = %d\n", i);
	ft_printf("MY printf i = %d\n", i);
	printf("OG printf longueur = %d\n", x);
	ft_printf("MY printf longueur = %d\n", x);
	printf("OG printf str = %s\n", str);
	ft_printf("MY printf str = %s\n", str);
	printf("OG printf De %c a %c\n", c, 'Z');
	ft_printf("MY printf De %c a %c\n", c, 'Z');
	printf("OG printf hexa = %x\n", i);
	ft_printf("MY printf hexa = %x\n", i);
	printf("OG printf HEXA = %X\n", i);
	ft_printf("MY printf HEXA = %X\n", i);
	printf("OG printf unsigned = %u\n", usl);
	ft_printf("MY printf unsigned = %u\n", usl);
	printf("OG printf PTR = %p\n", &str);
	ft_printf("MY printf PTR = %p\n", &str);
	printf("OG printf PTR = %");
	ft_printf("MY printf PTR = %");

	return (0);
}
*/
