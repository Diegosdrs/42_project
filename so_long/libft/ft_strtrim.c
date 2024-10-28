/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:25:08 by dsindres          #+#    #+#             */
/*   Updated: 2024/08/06 12:47:30 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <stdlib.h>

static int	ft_is_sep(const char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;
	int		i;
	int		len;

	if (!set || !s1)
		return (NULL);
	i = 0;
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_is_sep(s1[start], set))
		start++;
	while (end >= start && ft_is_sep(s1[end], set))
		end--;
	len = end - start + 1;
	if (len < 0)
		len = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (start <= end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
/*
int	main(void)
{
	char	*str;
	char	*set;

	str = "   xxxtripouille";
	set = " x";
	printf("%s", ft_strtrim(str, set));
	return (0);
}*/
