/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:36:35 by dsindres          #+#    #+#             */
/*   Updated: 2024/05/16 14:48:27 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <unistd.h>*/
#include <stdlib.h>

char	*ft_strdup(char *src)
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
/*
int	main(void)
{
	int	 i;
	char	*src;
	char	*dest;

	src = "diego";
	i = 0;
	dest = ft_strdup(src);
	while (dest[i])
	{
		write(1 , &dest[i], 1);
		i++;
	}
	return (0);
}*/
