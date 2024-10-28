/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:16:18 by dsindres          #+#    #+#             */
/*   Updated: 2024/05/23 10:04:50 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*tab;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start > ft_strlen(s))
		len = 0;
	tab = malloc (sizeof (char) * (len + 1));
	if (!tab)
		return (NULL);
	if (start < ft_strlen(s))
	{
		while (s[start] && len > 0)
		{
			tab[i] = s[start];
			i++;
			start++;
			len--;
		}
	}
	tab [i] = '\0';
	return (tab);
}
/*
int	main (void)
{
	char	*str;

	str = "diego aime la teuf";
	printf ("%s", ft_substr(str, 3, 22));
	return (0);
}*/
