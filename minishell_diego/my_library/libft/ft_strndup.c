/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:06:10 by artberna          #+#    #+#             */
/*   Updated: 2024/09/30 16:23:02 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_library.h"

char	*ft_strndup(const char *s, int len)
{
	char	*dup;
	int		i;

	if (len < 0)
		return (NULL);
	if ((int)ft_strlen(s) < len)
		len = ft_strlen(s);
	dup = ft_calloc(sizeof(char), len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*str;
	char	*new_str;

	str = "SAAAiojrnbiv oui oui AAAAAAALUT !";
	new_str = ft_strdup(str);
	printf("je suis la str : %s\n", str);
	printf("je suis la dup : %s\n", new_str);
	free(new_str);
	return (0);
}
*/
