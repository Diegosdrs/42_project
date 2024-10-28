/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:52:17 by dsindres          #+#    #+#             */
/*   Updated: 2024/07/24 11:11:14 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
