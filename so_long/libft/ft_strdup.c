/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:09:21 by dsindres          #+#    #+#             */
/*   Updated: 2024/05/22 11:07:04 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dest;

	i = 0;
	dest = NULL;
	while (src[i])
		i++;
	dest = malloc (sizeof(char) * (i + 1));
	if (dest == NULL)
		return (0);
	i = 0;
	while (src[i])
	{
		dest [i] = src [i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
