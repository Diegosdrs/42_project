/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:07:49 by dsindres          #+#    #+#             */
/*   Updated: 2024/05/22 11:18:02 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*ptr_dest;
	const unsigned char	*ptr_src;

	ptr_dest = (unsigned char *)dest;
	ptr_src = (const unsigned char *)src;
	i = 0;
	if (ptr_dest == ptr_src || n == 0)
		return (dest);
	if (ptr_dest < ptr_src)
	{
		while (i < n)
		{
			ptr_dest[i] = ptr_src[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i-- > 0)
			ptr_dest[i] = ptr_src[i];
	}
	return (dest);
}
/*
int main(void) 
{
    char str[] = "Hello, World!";
	char str2[] = "Hello, World!";
	
    ft_memmove(str + 2, str, 6);
	memmove(str2 + 2, str2, 6);
    printf("%s\n", str);
	printf("%s\n", str2);
    return 0;
}*/
