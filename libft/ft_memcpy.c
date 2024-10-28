/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:27:16 by dsindres          #+#    #+#             */
/*   Updated: 2024/05/23 10:10:26 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*ptr_dest;
	const unsigned char	*ptr_src;

	i = 0;
	ptr_dest = (unsigned char *)dest;
	ptr_src = (const unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		ptr_dest[i] = ptr_src[i];
		i++;
	}
	return (ptr_dest);
}
/*
int	main(void)
{
	int	src [] = {11, 56, 23, 25, 45};
	int	*copy;
	int	length;

	length = sizeof (int) * 5;
	copy = (int *) malloc (length);
	ft_memcpy(copy, src, length);
	length = 0;
	while (length < 5)
	{
		printf("%d", copy[length]);
		length++;
	}
	free (copy);
	return (0);
}*/