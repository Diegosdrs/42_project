/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:42:28 by dsindres          #+#    #+#             */
/*   Updated: 2024/05/22 13:58:41 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	unsigned char	*tab;

	i = 0;
	if (nmemb != 0 && size != 0 && (SIZE_MAX / nmemb) < size)
		return (NULL);
	tab = (unsigned char *) malloc (nmemb * size);
	if (tab == NULL)
		return (NULL);
	while (i < nmemb * size)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}
/*
int	main(void)
{
	int *array;
    int n;
	int	i;

	i = 0;
	n = 10;
    array = (int *)calloc(n, sizeof(int));
	while (i < n)
	{
		printf ("array[%d] = %d\n", i , array[i]);
		i++;
	}
	return (0);
}*/
