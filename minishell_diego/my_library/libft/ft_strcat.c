/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:13:53 by artberna          #+#    #+#             */
/*   Updated: 2024/10/11 12:19:00 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_library.h"

size_t	ft_strcat(char *dest, char *src)
{
	size_t	i;
	size_t	lengthdest;

	if (!dest || !src)
		return (0);
	lengthdest = 0;
	i = 0;
	while (dest[lengthdest])
		lengthdest++;
	while (src[i])
	{
		dest[lengthdest + i] = src[i];
		i++;
	}
	dest[lengthdest + i] = '\0';
	return (lengthdest + i);
}
