/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:32:16 by dsindres          #+#    #+#             */
/*   Updated: 2024/05/29 17:17:16 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = c;
		i++;
	}
	return (s);
}

bool	inside(const char *s, char c)
{
	if (!s)
		return (false);
	while (*s) 
	{
		if (*s == c)
			return (true);
		s++;
	}
	return (false);
}

static void	parse_flags(t_data *data)
{
	char	flag;
	
	while(inside(FLAGS, *data->s))
	{
		flag = *data->s;
		if('0' == flag)
			data->format.zero_pad = true;
		else if ('+' == flag)
			data->format.plus = true;
		else if (' ' == flag)
			data->format.space = true;
		else if ('#' == flag)
			data->format.hash = true;
		else if ('-' == flag)
			data->format.left_justified = true;
		data->s++;
	}
}

static int	atoiprintf(t_data *data)
{
	int	value;

	value = 0;
	while(*data->s >= 48 && *data->s <= 57)
	{
		value = (value * 10) + (*data->s - 48);
		data->s++;
	}
	return (value);
}

// Pourquoi mettre le if(data->s == *) dans la fonction get_value et non
// dans le parsing ?
// value prend donc une valeur meme si le width est inexistant avec la
// derniere ligne de la fonction.

// Pourquoi mettre data dans atoiprintf ? on ne devrait pas envoyer 
// *data->s ?

// Pas compris les jongles de type de variables entre get_value et atoiprintf

static void	get_value(t_data *data, int *value)
{
	if(*data->s == '*')
	{
		*value = va_arg(data->ap, int);
		data->s++;
		return ;
	}
	*value = atoiprintf(data);
}

int	parsing_str(t_data *data)
{
	ft_memset( &data->format, 0, sizeof(t_format));
	data->format.precision_value = -1;
	parse_flags(data);
	get_value(data, &data->format.width_value);
	if (*data->s == '.' && *(++data->s))
		get_value(data, &data->format.precision_value);
	if (!inside(SPECIFIERS, *data->s))
		return (PARSE_ERROR);
	else
	{
		// pourquoi etoile a *data->s et pas a celui d'avant ?
		data->format.specifier = *data->s;
		if (inside("diu", data->format.specifier))
			data->format.base = BASE_10;
		else if (inside("xXp", data->format.specifier))
		{
			data->format.base = BASE_16;
			if('X' == data->format.specifier)
				data->format.uppercase = true;
		}
	}
	return (OK);
}