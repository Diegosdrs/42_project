/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:52:00 by artberna          #+#    #+#             */
/*   Updated: 2024/06/20 14:57:44 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_library.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *) s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "salut mon GARS";

	printf("%s\n", str);
	ft_bzero(str, 1);
	printf("%s\n", str);
	return (0);
}
*/