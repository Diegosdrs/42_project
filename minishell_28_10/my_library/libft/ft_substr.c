/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:25:59 by artberna          #+#    #+#             */
/*   Updated: 2024/06/18 09:57:35 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_library.h"

static size_t	ft_strlensub(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (ft_strlensub(s) < start)
		len = 0;
	else if (ft_strlensub(s) - start < len)
		len = ft_strlensub(s) - start;
	new_str = (char *)malloc(sizeof(char) * len + 1);
	if (!new_str)
		return (NULL);
	if (start < ft_strlensub(s))
	{
		while (s[start] && len > 0)
		{
			new_str[i] = s[start];
			start++;
			i++;
			len--;
		}
	}
	new_str[i] = '\0';
	return (new_str);
}

/*
#include <stdio.h>

int	main(void)
{
	char			s[] = "hello";
	char			*new_str;
	unsigned int	i;
	int				j;

	i = 1;
	j = 55;
	new_str = ft_substr(s, i, j);
	if (new_str)
	{
		printf(":%s:\n", new_str);
		free(new_str);
	}
	else
	{
		printf("Allocation échouée\n");
	}
	return (0);
}
*/
