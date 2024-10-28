/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:29:09 by artberna          #+#    #+#             */
/*   Updated: 2024/06/18 09:56:20 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_library.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptrs;
	size_t				i;

	i = 0;
	ptrs = (const unsigned char *)s;
	while (i < n)
	{
		if (ptrs[i] == (unsigned char)c)
			return ((void *)&ptrs[i]);
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>

int	main(void)
{
	const char	*str = "Bonjour le monde!";
	char		target = 'l';
	size_t		n;
	void 		*result;

	n = 16;
	result = ft_memchr(str, target, n);
	if (result != NULL)
		printf("Caractère trouvé à l'adresse : %p\n", result);
	else
		printf("Caractère non trouvé.\n");

	return (0);
}
*/