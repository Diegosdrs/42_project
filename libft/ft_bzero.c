/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:12:37 by dsindres          #+#    #+#             */
/*   Updated: 2024/05/16 15:59:08 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>
*/

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}
/*
int	main(void)
{
	int	tab[4] = {6, 7, 8, 9};
	int	i;

	i = 0;
	while (i < 4)
	{
		printf("%d", tab[i]);
		i++;
	}
	printf ("\n");
	i = 0;
	ft_bzero(tab, 16);
	while (i < 4)
	{
		printf("%d", tab[i]);
		i++;
	}
	return (0);
}*/
