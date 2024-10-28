/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:37:03 by dsindres          #+#    #+#             */
/*   Updated: 2024/05/23 10:03:52 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <bsd/string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t t)
{
	size_t	i;
	size_t	length_dest;
	size_t	length_src;

	i = 0;
	length_dest = ft_strlen(dest);
	length_src = ft_strlen(src);
	if (length_dest >= t || t == 0)
		return (length_src + t);
	while (src[i] && (length_dest + i) < (t - 1))
	{
		dest[length_dest + i] = src[i];
		i++;
	}
	dest[length_dest + i] = '\0';
	return (length_dest + length_src);
}
/*
int	main(void)
{
	char	dest [] = "diego";
	char	dest2 [] = "diego";
	char	*src;
	int	i;

	i = 10;
	src = "123";
	printf("%s\n", src);
	ft_strlcat(dest, src, i);
	printf("%s\n", dest);
	printf("la valeur de retour vaut : %zu\n\n", ft_strlcat(dest, src, i));
	strlcat(dest2, src, i);
	printf("%s\n", dest2);
	printf("la valeur de retour vaut : %zu\n", strlcat(dest2, src, i));
	return (0);
}*/
