/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:13:50 by dsindres          #+#    #+#             */
/*   Updated: 2024/06/20 11:00:10 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	length;
	size_t	count;

	length = 0;
	count = 0;
	while (src[length])
		length++;
	if (size <= 0)
		return (length);
	while (src[count] && count < (size - 1))
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (length);
}

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
int main(void)
{
	char *str;
	char c;
	char  **str2;
	int i;

	i = 0;
	str = "diego diego diego diego     ff";
	c = ' ';
	str2 = ft_split(str, c);
	while (str2[i])
	{
		printf("%s\n", str2[i]);
		i++;
	}
	i = 0;
	while (str2[i])
	{
		free(str2[i]);
		i++;
	}
	free (str2);
	return (0);
}
*/