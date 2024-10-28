/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:43:22 by artberna          #+#    #+#             */
/*   Updated: 2024/06/18 09:57:21 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_library.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	char			*new_str;

	if (!s || !f)
		return (NULL);
	len = 0;
	while (s[len])
		len++;
	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	len = 0;
	while (s[len])
	{
		new_str[len] = f(len, s[len]);
		len++;
	}
	new_str[len] = '\0';
	return (new_str);
}
/*
char	ft_addmore(unsigned int i, char c)
{
	return (c + i);
}

int	main(void)
{
	char	*str;
	char	*dbl;

	str = "aabcdefgh";
	dbl = ft_strmapi(str, &ft_addmore);
	printf("%s\n", dbl);
	free (dbl);
	return (0);
}
*/