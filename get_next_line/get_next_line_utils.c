/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:46:32 by dsindres          #+#    #+#             */
/*   Updated: 2024/09/14 12:40:29 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
/* 
int	is_n(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	if (buffer[i] == '\n')
		return (1);
	return (0);
} */

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	unsigned char	*tab;

	i = 0;
	if (nmemb != 0 && size != 0 && (SIZE_MAX / nmemb) < size)
		return (NULL);
	tab = (unsigned char *) malloc (nmemb * size);
	if (tab == NULL)
		return (NULL);
	while (i < nmemb * size)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	new_str = malloc (sizeof (char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_str)
		return (NULL);
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new_str[i] = s2[j];
		j++;
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}
