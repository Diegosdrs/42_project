/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:29:07 by artberna          #+#    #+#             */
/*   Updated: 2024/06/18 09:56:23 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_library.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptrs1;
	const unsigned char	*ptrs2;

	ptrs1 = (const unsigned char *)s1;
	ptrs2 = (const unsigned char *)s2;
	while (n--)
	{
		if (*ptrs1 != *ptrs2)
			return (*ptrs1 - *ptrs2);
		ptrs1++;
		ptrs2++;
	}
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	const char	*s1 = "Hewlo";
	const char	*s2 = "Hello";
	size_t		n;
	int			result;

	n = 2;
	result = ft_memcmp(s1, s2, n);
	if (result == 0)
		printf("Identiques pour les %zu premiers octets.\n", n);
	else if (result < 0)
		printf("s1 est inférieure pour les %zu premiers octets.\n", n);
	else
		printf("s1 est supérieure pour les %zu premiers octets.\n", n);
	return (0);
}
*/