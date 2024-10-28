/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:56:37 by artberna          #+#    #+#             */
/*   Updated: 2024/06/18 09:56:32 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_library.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char) c;
		i++;
	}
	return (ptr);
}

/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "salut mon GARS";
	char	*str2;

	printf("%s\n", str);
	str2 = ft_memset(str, 'a', 12);
	printf("%s\n", str2);
	return (0);
}
*/