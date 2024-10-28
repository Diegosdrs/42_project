/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:22:45 by dsindres          #+#    #+#             */
/*   Updated: 2024/05/22 11:55:19 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*ptr_s1;
	const unsigned char	*ptr_s2;

	i = 0;
	ptr_s1 = (const unsigned char *)s1;
	ptr_s2 = (const unsigned char *)s2;
	if (i == n)
		return (0);
	while (i < n)
	{
		if (ptr_s1[i] != ptr_s2[i])
			return ((int)ptr_s1[i] - (int)ptr_s2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	*str1 = "diebooooabuh";
	char	*str2 = "dieaoooxjb3dhi";
	
	printf ("%d", ft_memcmp(str1, str2, 6));
	return (0);
}*/
