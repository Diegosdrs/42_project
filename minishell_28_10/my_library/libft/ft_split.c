/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:18:55 by artberna          #+#    #+#             */
/*   Updated: 2024/07/10 17:53:27 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_library.h"

static int	count_wrd(char const *s, char c)
{
	int	i;
	int	count;
	int	inside;

	count = 0;
	i = 0;
	inside = 0;
	while (s[i])
	{
		if (s[i] == c)
			inside = 0;
		else if (!inside)
		{
			inside = 1;
			count++;
		}
	i++;
	}
	return (count);
}

static char	*ft_strdupsplit(const char *s, int limit)
{
	char	*dup;
	int		i;

	i = 0;
	dup = ft_calloc(sizeof(char), limit + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < limit)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static char	**free_malloc(char **s, int index)
{
	while (index >= 0)
	{
		free(s[index]);
		index--;
	}
	free(s);
	return (NULL);
}

static char	**ft_splitter(char **dbl_str, char const *s, char c)
{
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == c))
			i++;
		start = i;
		while (s[i] && (s[i] != c))
			i++;
		if (i > start)
		{
			dbl_str[j] = ft_strdupsplit(s + start, i - start);
			if (!dbl_str[j])
				return (free_malloc(dbl_str, j - 1));
			j++;
		}
	}
	dbl_str[j] = NULL;
	return (dbl_str);
}

char	**ft_split(char const *s, char c)
{
	char	**dbl_str;
	int		lengthdbl;

	if (!s)
		return (NULL);
	lengthdbl = count_wrd(s, c);
	dbl_str = ft_calloc(sizeof(char *), (lengthdbl + 1));
	if (!dbl_str)
		return (NULL);
	dbl_str[lengthdbl] = NULL;
	return (ft_splitter(dbl_str, s, c));
}
/*
int	main(void)
{
	char	*str;
	char	c;
	int		i;
	char	**dbl_str;

	i = 0;
	str = "xxdiegoxxdiqgoxxdiegitoxxx";
	c = 'x';
	dbl_str = ft_split(str, c);
	if (!dbl_str)
	{
		printf("Allocation échouée\n");
		return (1);
	}
	while (dbl_str[i])
	{
		printf("%s\n", dbl_str[i]);
		i++;
	}
	i = 0;
	if (dbl_str)
	{
		while (dbl_str[i])
		{
			free(dbl_str[i]);
			i++;
		}
	}
	free(dbl_str);
	return (0);
}
*/