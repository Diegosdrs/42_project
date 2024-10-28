/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:29:26 by dsindres          #+#    #+#             */
/*   Updated: 2024/05/29 18:57:54 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft.h"
#include <stdarg.h>
#include <stdbool.h>
#include <limits.h>

#define FLAGS "+ 0-#"
#define NUMBERS "0123456789"
#define SPECIFIERS "cspdiuxX%"

typedef enum
{
	OK = 0,
	MALLOC_ERROR = -100,
	PARSE_ERROR = -100,
}	e_error;

typedef enum
{
	BASE_2 = 2,
	BASE_8 = 8,
	BASE_10 = 10,
	BASE_16 = 16,
}	e_base;

typedef struct s_format
{
	bool	left_justified;
	bool	plus;
	bool	space;
	bool	hash;
	bool	zero_pad;
	char	specifier;
	int		width_value;
	int		precision_value;
	bool	uppercase;
	e_base	base;
}	t_format;

typedef struct	s_data
{
	const char	*s;
	va_list		ap;
	int			chars_written;
	t_format	format;
}	t_data;

bool	inside(const char *s, char c);
int		parsing_str(t_data *data);
int		init_data (t_data *data, const char *str);
int		ft_printf(const char *str, ...);
void	render_str(t_data *data);
void	print_char(t_data *data, int c);
void	ft_putchar_fd_n(char c, int fd, int n);
void	ft_putchar_fd(char c, int fd);
void	*ft_memset(void *s, int c, size_t n);
void	print_str(t_data *data, char *s);
void	ft_putstr_fd(char *s, int fd);
void	ft_printstr(char *s, int precision, t_data *data);
int		strlen(const char *s);









#endif