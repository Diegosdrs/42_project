/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:29:26 by dsindres          #+#    #+#             */
/*   Updated: 2024/09/14 14:15:49 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include <limits.h>
# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdint.h>

typedef struct s_data
{
	const char	*s;
	va_list		ap;
	int			chars_written;
	char		*base16;
}	t_data;

int		ft_printf(const char *str, ...);
void	printchar(char c, t_data *data);
int		init_data(t_data *data, const char *str);
int		parsing_str(t_data *data);
int		print_str(char *s, t_data *data);
int		print_numbers(long n, int base, t_data *data);
void	print_pointer(unsigned long n, t_data *data, int interupt);

#endif