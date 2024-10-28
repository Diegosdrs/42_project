/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:08:52 by artberna          #+#    #+#             */
/*   Updated: 2024/09/12 10:19:11 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_library.h"

static size_t	ft_strlentrim(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	is_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	int		strt;
	int		end;
	int		i;
	int		total_len;

	if (!set || !s1)
		return (NULL);
	i = 0;
	strt = 0;
	end = ft_strlentrim(s1) - 1;
	while (s1[strt] && is_set(s1[strt], set))
		strt++;
	while (end >= strt && is_set(s1[end], set))
		end--;
	total_len = end - strt + 1;
	if (total_len < 0)
		total_len = 0;
	new_str = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!new_str)
		return (NULL);
	while (strt <= end)
		new_str[i++] = s1[strt++];
	new_str[i] = '\0';
	return (new_str);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*s1;
	char	*set;
	char	*trim;

	s1 = "aolaolaol";
	set = "aol";
	trim = ft_strtrim(s1, set);
	printf(":%s:\n", trim);
	return (0);
}
*/