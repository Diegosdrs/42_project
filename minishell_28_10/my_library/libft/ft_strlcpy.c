/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:06:43 by artberna          #+#    #+#             */
/*   Updated: 2024/06/18 09:57:15 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_library.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t siz)
{
	size_t	i;
	size_t	length;

	length = 0;
	i = 0;
	while (src[length])
		length++;
	if (siz <= 0)
		return (length);
	while (src[i] && i < siz - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (length);
}

/*
#include <stdio.h>

int	main(void)
{
	char	src[] = "Hello, world    !";
	char	dest[10];

	size_t	copied_chars = ft_strlcpy(dest, src, 0);

	printf("Source : %s\n", src);
	printf("Destination : %s\n", dest);
	printf("STRLEN SRC : %lu\n", copied_chars);
	return (0);
}
*/