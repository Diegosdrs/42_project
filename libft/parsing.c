/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:32:16 by dsindres          #+#    #+#             */
/*   Updated: 2024/07/24 11:11:07 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
