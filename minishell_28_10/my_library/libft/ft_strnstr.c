/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:40:07 by artberna          #+#    #+#             */
/*   Updated: 2024/06/18 09:57:26 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_library.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (big == NULL && little == NULL)
		return (NULL);
	if (!little[j])
		return ((char *)&big[i]);
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j] && little[j] == big[i + j] && i + j < len)
			j++;
		if (!little[j])
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>

int	main(void)
{
	const char	*big = "okmokdfm kmofkdmo mHello World!";
	const char	*little = "H";
	size_t		len;
	char		*result;

	len = 50;
	result = ft_strnstr(big, little, len);
	if (result != NULL)
		printf("Substring found : %s\n",result);
	else
		printf("Substring not found.\n");

	return (0);
}
*/
