/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:59:26 by dsindres          #+#    #+#             */
/*   Updated: 2024/05/23 10:57:16 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <stdlib.h>

static size_t	count_words(char const *s, char sep)
{
	size_t	i;
	size_t	count;
	int		in_word;

	i = 0;
	in_word = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != sep && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (s[i] == sep)
			in_word = 0;
		i++;
	}
	return (count);
}

static int	add_split(char **str, int index, size_t len)
{
	str[index] = malloc(sizeof(char) * len);
	if (!str[index])
	{
		while (index >= 0)
		{
			free (str[index]);
			index--;
		}
		free (str);
		return (1);
	}
	return (0);
}

static int	ft_splitter(char **str, char const *s, char c)
{
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		len = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			len++;
		}
		if (len > 0)
		{
			if (add_split(str, j, len + 1) == 1)
				return (1);
			ft_strlcpy(str[j], &s[i - len], len + 1);
			j++;
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	count;

	if (!s)
		return (NULL);
	count = count_words (s, c);
	str = malloc(sizeof (char *) * (count + 1));
	if (!str)
		return (NULL);
	str[count] = NULL;
	if (ft_splitter(str, s, c) == 1)
		return (NULL);
	return (str);
}
/*
int	main(void)
{
	char	*str;
	char	c;
	char	**s;
	int		i;

	i = 0;
	str = "split  ||this|for|me|||||!|";
	c = '|';
	s = ft_split(str, c);
	while (s[i])
	{
		printf ("%s\n", s[i]);
		i++;
	}
	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (0);
} */
