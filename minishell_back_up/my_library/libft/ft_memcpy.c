/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:07:19 by artberna          #+#    #+#             */
/*   Updated: 2024/06/18 09:56:25 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_library.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*ptrdest;
	const unsigned char	*ptrsrc;

	if (n == 0)
		return (dest);
	if (dest == NULL && src == NULL)
		return (NULL);
	ptrdest = (unsigned char *)dest;
	ptrsrc = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		ptrdest[i] = ptrsrc[i];
		i++;
	}
	return (dest);
}

/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "salut mon GARS";
	char	str2[99];
	char	*result;

	result = ft_memcpy(str2, str, 17);
	printf("src : %s\n", str);
	printf("dest : %s\n", str2);
	printf("result : %s\n", result);
	return (0);
}
*/