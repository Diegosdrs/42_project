/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 09:57:35 by dsindres          #+#    #+#             */
/*   Updated: 2024/05/20 10:22:21 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*ptr_s;
	unsigned char		uc;

	i = 0;
	uc = (unsigned char)c;
	ptr_s = (const unsigned char *)s;
	while (i < n)
	{
		if (ptr_s[i] == uc)
			return ((void *)&ptr_s[i]);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	*str;
	int	c;
	char	*newstr;

	str = "diego ogdee";
	c = 'o';
	newstr = ft_memchr(str, c, 7);
	printf ("%s", newstr);
	return (0);
}*/
