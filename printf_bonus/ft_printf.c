/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:27:05 by dsindres          #+#    #+#             */
/*   Updated: 2024/05/29 16:57:38 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	init_data (t_data *data, const char *str)
{
	data->s = str;
	data->chars_written = 0;
	return OK;
}

int	ft_printf(const char *str, ...)
{
	t_data	data;
	
	va_start(data.ap, str);
	if (init_data(&data, str))
		return (-1);
	while (*data.s)
	{
		if (*data.s == '%' && *(++data.s))
			{
				if (parsing_str(&data))
					return (PARSE_ERROR);
				render_str(&data);
			}
		else
			ft_putchar_fd(*data.s, STDOUT_FILENO);
		data.s++;
	}
	return(0);
}