/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:42:09 by dsindres          #+#    #+#             */
/*   Updated: 2024/05/17 12:34:45 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <stdlib.h>

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
/*
int	main(void)
{
	char	*dest;
	char	*src;
	int	i;

	i = 0;
	src = "12345";
	while(src[i])
	{
		i++;
	}
	dest = malloc (sizeof (char) * (i + 1));
	printf("%s\n", src);
	ft_strlcpy(dest, src, 30);
	printf("%s\n", dest);
	return (0);
}*/
