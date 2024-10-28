/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:52:17 by dsindres          #+#    #+#             */
/*   Updated: 2024/05/29 18:58:13 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
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
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_putchar_fd_n(char c, int fd, int n)
{
	if (n <= 0)
		return ;
	while (n > 0)
	{
		write(fd, &c, 1);
		n--;
	}
	return ;
}

void	print_char(t_data *data, int c)
{
	int	width;

	width = data->format.width_value;
	if(width > 1)
	{
		if (data->format.left_justified)
		{
			ft_putchar_fd_n((char)c, STDOUT_FILENO, 1);
			ft_putchar_fd_n(' ', STDOUT_FILENO, width - 1);
		}
		else
		{
			ft_putchar_fd_n(' ', STDOUT_FILENO, width - 1);
			ft_putchar_fd_n((char)c, STDOUT_FILENO, 1);
		}
	}
	else
		ft_putchar_fd_n((char)c, STDOUT_FILENO, 1);
}

void	ft_printstr(char *s, int precision, t_data *data)
	{
		if (precision <= 0)
			return ;
		while (precision && s)
		{
			ft_putchar_fd(*s, STDOUT_FILENO);
			precision--;
		}
	}

int	strlen(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL || !*s)
		return 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

void	print_str(t_data *data, char *s)
{
	if (!s)
		s = "(null)";
	if (data->format.left_justified)
	{
		if (data->format.precision_value >= 0)
			ft_printstr(s, data->format.precision_value, data);
		else
			ft_printstr(s, strlen(s), data);
	}
}

void	render_str(t_data *data)
{
	if (data->format.specifier == '%')
		ft_putchar_fd('%', STDOUT_FILENO);
	else if (data->format.specifier == 'c')
		print_char(data, va_arg(data->ap, int));
	else if (data->format.specifier == 's')
		print_str(data, va_arg(data->ap, char *));
}
