/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:43:31 by artberna          #+#    #+#             */
/*   Updated: 2024/10/11 09:55:20 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_library.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	int		i;
	int		j;
	int		length;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	length = (ft_strlen(s1) + ft_strlen(s2));
	i = 0;
	j = 0;
	new_str = (char *)malloc(sizeof(char) * (length + 1));
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, s1, ft_strlen(s1));
	ft_memcpy(new_str + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (free(s1), new_str);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*s1;
	char	*s2;
	char	*concat;

	s1 = "Hello";
	s2 = "CHACAL";
	concat = ft_strjoin(s1, s2);
	printf(":%s:\n", concat);
	return (0);
}
*/