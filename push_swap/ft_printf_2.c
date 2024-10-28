/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:42:36 by dsindres          #+#    #+#             */
/*   Updated: 2024/07/09 11:06:25 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parsing_str(t_data *data)
{
	if (*data->s == '%')
		printchar('%', data);
	else if (*data->s == 'c')
		printchar(va_arg(data->ap, int), data);
	else if (*data->s == 's')
		print_str(va_arg(data->ap, char *), data);
	else if (*data->s == 'p')
		print_pointer((unsigned long)va_arg(data->ap, void *), data, 0);
	else if (*data->s == 'd' || *data->s == 'i')
		print_numbers(va_arg(data->ap, int), 10, data);
	else if (*data->s == 'x' || *data->s == 'X')
		print_numbers(va_arg(data->ap, unsigned int), 16, data);
	else if (*data->s == 'u')
		print_numbers(va_arg(data->ap, unsigned int), 10, data);
	return (0);
}

void	printchar(char c, t_data *data)
{
	if (*data->s == 'X')
	{
		if (c >= 97 && c <= 122)
			c -= 32;
	}
	write(1, &c, 1);
	data->chars_written++;
	return ;
}

int	print_str(char *s, t_data *data)
{
	int	i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i])
	{
		printchar(s[i], data);
		i++;
	}
	return (i);
}

void	print_pointer(unsigned long n, t_data *data, int interupt)
{
	if (n == 0)
	{
		print_str("(nil)", data);
		return ;
	}
	if (interupt == 0)
		print_str("0x", data);
	if (n >= 16)
	{
		print_pointer(n / 16, data, 1);
	}
	printchar (data->base16[n % 16], data);
}

int	print_numbers(long n, int base, t_data *data)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (n < 0)
	{
		n = -n;
		printchar('-', data);
	}
	if (n < (long)base)
	{
		printchar(symbols[n], data);
		return (0);
	}
	else
	{
		count = print_numbers(n / base, base, data);
		return (count + print_numbers(n % base, base, data));
	}
}
