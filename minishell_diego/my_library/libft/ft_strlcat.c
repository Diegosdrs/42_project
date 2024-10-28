/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:03:25 by artberna          #+#    #+#             */
/*   Updated: 2024/10/11 09:36:32 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_library.h"

size_t	ft_strlcat(char *dest, char *src, size_t n)
{
	size_t	i;
	size_t	lengthdest;
	size_t	lengthsrc;

	lengthdest = 0;
	lengthsrc = 0;
	i = 0;
	while (src[lengthsrc])
		lengthsrc++;
	while (dest[lengthdest] && lengthdest < n)
		lengthdest++;
	if (n == 0 || n <= lengthdest)
		return (n + lengthsrc);
	while (src[i] && (lengthdest + i) < (n - 1))
	{
		dest[lengthdest + i] = src[i];
		i++;
	}
	dest[lengthdest + i] = '\0';
	free(src);
	return (lengthsrc + lengthdest);
}
