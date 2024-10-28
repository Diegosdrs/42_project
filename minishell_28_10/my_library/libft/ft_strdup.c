/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:06:10 by artberna          #+#    #+#             */
/*   Updated: 2024/06/18 09:57:02 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_library.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;

	i = 0;
	while (s[i])
		i++;
	dup = malloc(sizeof(char) * i + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
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
