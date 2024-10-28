/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:41:46 by dsindres          #+#    #+#             */
/*   Updated: 2024/07/09 11:06:08 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_data(t_data *data, const char *str)
{
	data->s = str;
	data->chars_written = 0;
	data->base16 = "0123456789abcdef";
	return (0);
}

int	ft_printf(const char *str, ...)
{
	t_data	data;

	va_start(data.ap, str);
	if (init_data(&data, str))
		return (-1);
	if (!str)
		return (-1);
	while (*data.s)
	{
		if (*data.s == '%' && *data.s + 1 == '\0')
			return (-1);
		if (*data.s == '%' && *(++data.s))
		{
			if (parsing_str(&data))
				return (1);
		}
		else
		{
			printchar(*data.s, &data);
		}
		data.s++;
	}
	va_end(data.ap);
	return (data.chars_written);
}
