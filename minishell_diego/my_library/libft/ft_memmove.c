/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:48:42 by artberna          #+#    #+#             */
/*   Updated: 2024/06/18 09:56:28 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_library.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*ptrdest;
	const unsigned char	*ptrsrc;

	ptrdest = (unsigned char *)dest;
	ptrsrc = (const unsigned char *)src;
	if (ptrdest == ptrsrc || n == 0)
		return (dest);
	if (ptrdest < ptrsrc)
	{
		i = 0;
		while (i++ < n)
			ptrdest[i - 1] = ptrsrc[i - 1];
	}
	else
	{
		i = n;
		while (i-- > 0)
			ptrdest[i] = ptrsrc[i];
	}
	return (ptrdest);
}

/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*str = strdup("ACDEFGB");
	char	*str2 = strdup("ABCDE");
	char	*result;

	result = ft_memmove(str + 2, str, 5);
	printf("src : %s\n", str);
	printf("dest : %s\n", str2);
	printf("result : %s\n", result);
	free(str);
	free(str2);
	return (0);
}
*/
